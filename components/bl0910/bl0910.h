#pragma once
 
#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"
#include "esphome/components/sensor/sensor.h"
 
namespace esphome {
namespace bl0910 {

class BL0910 : public PollingComponent, public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_TRAILING, spi::DATA_RATE_1MHZ> {
  public:
    void set_voltage_sensor(sensor::Sensor *voltage_sensor) { voltage_sensor_ = voltage_sensor; }
   
    void set_current_sensor_1(sensor::Sensor *current_sensor_1) { current_sensor_1_ = current_sensor_1; }
    void set_current_sensor_2(sensor::Sensor *current_sensor_2) { current_sensor_2_ = current_sensor_2; }
    void set_current_sensor_3(sensor::Sensor *current_sensor_3) { current_sensor_3_ = current_sensor_3; }
    void set_current_sensor_4(sensor::Sensor *current_sensor_4) { current_sensor_4_ = current_sensor_4; }
    void set_current_sensor_5(sensor::Sensor *current_sensor_5) { current_sensor_5_ = current_sensor_5; }
    void set_current_sensor_6(sensor::Sensor *current_sensor_6) { current_sensor_6_ = current_sensor_6; }
    void set_current_sensor_7(sensor::Sensor *current_sensor_7) { current_sensor_7_ = current_sensor_7; }
    void set_current_sensor_8(sensor::Sensor *current_sensor_8) { current_sensor_8_ = current_sensor_8; }
    void set_current_sensor_9(sensor::Sensor *current_sensor_9) { current_sensor_9_ = current_sensor_9; }
    void set_current_sensor_10(sensor::Sensor *current_sensor_10) { current_sensor_10_ = current_sensor_10; }
    
    void set_power_sensor_1(sensor::Sensor *power_sensor_1) { power_sensor_1_ = power_sensor_1; }
    void set_power_sensor_2(sensor::Sensor *power_sensor_2) { power_sensor_2_ = power_sensor_2; }
    void set_power_sensor_3(sensor::Sensor *power_sensor_3) { power_sensor_3_ = power_sensor_3; }
    void set_power_sensor_4(sensor::Sensor *power_sensor_4) { power_sensor_4_ = power_sensor_4; }
    void set_power_sensor_5(sensor::Sensor *power_sensor_5) { power_sensor_5_ = power_sensor_5; }
    void set_power_sensor_6(sensor::Sensor *power_sensor_6) { power_sensor_6_ = power_sensor_6; }
    void set_power_sensor_7(sensor::Sensor *power_sensor_7) { power_sensor_7_ = power_sensor_7; }
    void set_power_sensor_8(sensor::Sensor *power_sensor_8) { power_sensor_8_ = power_sensor_8; }
    void set_power_sensor_9(sensor::Sensor *power_sensor_9) { power_sensor_9_ = power_sensor_9; }
    void set_power_sensor_10(sensor::Sensor *power_sensor_10) { power_sensor_10_ = power_sensor_10; }
    
    void set_energy_sensor_1(sensor::Sensor *energy_sensor_1) { energy_sensor_1_ = energy_sensor_1; }
    void set_energy_sensor_2(sensor::Sensor *energy_sensor_2) { energy_sensor_2_ = energy_sensor_2; }
    void set_energy_sensor_3(sensor::Sensor *energy_sensor_3) { energy_sensor_3_ = energy_sensor_3; }
    void set_energy_sensor_4(sensor::Sensor *energy_sensor_4) { energy_sensor_4_ = energy_sensor_4; }
    void set_energy_sensor_5(sensor::Sensor *energy_sensor_5) { energy_sensor_5_ = energy_sensor_5; }
    void set_energy_sensor_6(sensor::Sensor *energy_sensor_6) { energy_sensor_6_ = energy_sensor_6; }
    void set_energy_sensor_7(sensor::Sensor *energy_sensor_7) { energy_sensor_7_ = energy_sensor_7; }
    void set_energy_sensor_8(sensor::Sensor *energy_sensor_8) { energy_sensor_8_ = energy_sensor_8; }
    void set_energy_sensor_9(sensor::Sensor *energy_sensor_9) { energy_sensor_9_ = energy_sensor_9; }
    void set_energy_sensor_10(sensor::Sensor *energy_sensor_10) { energy_sensor_10_ = energy_sensor_10; }
   
    void set_energy_sensor_sum(sensor::Sensor *energy_sensor_sum) { energy_sensor_sum_ = energy_sensor_sum; }
 
    void loop() override;
 
    void update() override;
    void setup() override;
    void dump_config() override;
 
  protected:
    sensor::Sensor *voltage_sensor_{nullptr};
    sensor::Sensor *current_sensor_1_{nullptr};
    sensor::Sensor *current_sensor_2_{nullptr};
    sensor::Sensor *current_sensor_3_{nullptr};
    sensor::Sensor *current_sensor_4_{nullptr};
    sensor::Sensor *current_sensor_5_{nullptr};
    sensor::Sensor *current_sensor_6_{nullptr};
    sensor::Sensor *current_sensor_7_{nullptr};
    sensor::Sensor *current_sensor_8_{nullptr};
    sensor::Sensor *current_sensor_9_{nullptr};
    sensor::Sensor *current_sensor_10_{nullptr};
   
    sensor::Sensor *power_sensor_1_{nullptr};
    sensor::Sensor *power_sensor_2_{nullptr};
    sensor::Sensor *power_sensor_3_{nullptr};
    sensor::Sensor *power_sensor_4_{nullptr};
    sensor::Sensor *power_sensor_5_{nullptr};
    sensor::Sensor *power_sensor_6_{nullptr};
    sensor::Sensor *power_sensor_7_{nullptr};
    sensor::Sensor *power_sensor_8_{nullptr};
    sensor::Sensor *power_sensor_9_{nullptr};
    sensor::Sensor *power_sensor_10_{nullptr};
    
    sensor::Sensor *energy_sensor_1_{nullptr};
    sensor::Sensor *energy_sensor_2_{nullptr};
    sensor::Sensor *energy_sensor_3_{nullptr};
    sensor::Sensor *energy_sensor_4_{nullptr};
    sensor::Sensor *energy_sensor_5_{nullptr};
    sensor::Sensor *energy_sensor_6_{nullptr};
    sensor::Sensor *energy_sensor_7_{nullptr};
    sensor::Sensor *energy_sensor_8_{nullptr};
    sensor::Sensor *energy_sensor_9_{nullptr};
    sensor::Sensor *energy_sensor_10_{nullptr};
   
    sensor::Sensor *energy_sensor_sum_{nullptr};
 
    uint8_t checksum_calc(uint8_t* data);
    bool checksum_check(uint8_t* data);
    void bl0910_write_data(uint8_t addr, uint8_t data_h, uint8_t data_m, uint8_t data_l);
    int32_t bl0910_read_data(uint8_t addr);
  };
}  // namespace bl0910
}  // namespace esphome
