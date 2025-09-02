#include "tas5825m.h"
#include "tas5825m_const.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"
#include <cinttypes>

namespace esphome {
namespace tas5825m {

static const char *const TAG = "tas5825m";

// Mark the component as failed; use only in setup
#define TAS5825M_ERROR_FAILED(func) \
  if (!(func)) { \
    this->mark_failed(); \
    return; \
  }

void TAS5825M::setup() {
  TAS5825M_ERROR_FAILED(this->write_byte(TAS5825M_GPIO_CTRL, 0x04)); // Set GPIO2 as output
  TAS5825M_ERROR_FAILED(this->write_byte(TAS5825M_GPIO2_SEL, 0b1011)); // Set GPIO2 as FAULTZ output
  TAS5825M_ERROR_FAILED(this->write_byte(TAS5825M_SAP_CTRL1, 0x00)); // Set audio to 16bit
  TAS5825M_ERROR_FAILED(this->write_byte(TAS5825M_DEVICE_CTRL2, 0x03)); // Enable DSP and set PLAY mode
}

void TAS5825M::dump_config() {
  ESP_LOGCONFIG(TAG, "TAS5825M Audio Codec:");

  if (this->is_failed()) {
    ESP_LOGCONFIG(TAG, "  Failed to initialize");
    return;
  }
}

bool TAS5825M::set_volume(float volume) {
  volume = clamp(volume, 0.0f, 1.0f);
  uint8_t reg = remap<uint8_t, float>(volume, 0.0f, 1.0f, 255, 0);
  ESP_LOGV(TAG, "Setting TAS5825M_DIG_VOL to %u (volume: %f)", reg, volume);
  return this->write_byte(TAS5825M_DIG_VOL, reg);
}

float TAS5825M::volume() {
  uint8_t reg;
  this->read_byte(TAS5825M_DIG_VOL, &reg);
  return remap<float, uint8_t>(reg, 255, 0, 0.0f, 1.0f);
}

bool TAS5825M::set_mute_state_(bool mute_state) {
  uint8_t reg;

  this->is_muted_ = mute_state;

  if (!this->read_byte(TAS5825M_DEVICE_CTRL2, &reg)) {
    return false;
  }

  ESP_LOGV(TAG, "Read TAS5825M_DEVICE_CTRL2: %u", reg);

  if (mute_state) {
    reg |= BIT(3);
  } else {
    reg &= ~BIT(3);
  }

  ESP_LOGV(TAG, "Setting TAS5825M_DEVICE_CTRL2 to %u (muted: %s)", reg, YESNO(mute_state));
  return this->write_byte(TAS5825M_DEVICE_CTRL2, reg);
}

}  // namespace tas5825m
}  // namespace esphome
