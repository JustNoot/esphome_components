import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, binary_sensor, text_sensor, spi
from esphome.const import *

DEPENDENCIES = ['spi']
AUTO_LOAD = ['spi', 'sensor', 'text_sensor', 'binary_sensor']

bl0910_ns = cg.esphome_ns.namespace('bl0910')
BL0910 = bl0910_ns.class_('BL0910', cg.PollingComponent, spi.SPIDevice)


CONF_V = "voltage"

CONF_I1 = "current_1"
CONF_I2 = "current_2"
CONF_I3 = "current_3"
CONF_I4 = "current_4"
CONF_I5 = "current_5"
CONF_I6 = "current_6"
CONF_I7 = "current_7"
CONF_I8 = "current_8"
CONF_I9 = "current_9"
CONF_I10 = "current_10"

CONF_P1 = "power_1"
CONF_P2 = "power_2"
CONF_P3 = "power_3"
CONF_P4 = "power_4"
CONF_P5 = "power_5"
CONF_P6 = "power_6"
CONF_P7 = "power_7"
CONF_P8 = "power_8"
CONF_P9 = "power_9"
CONF_P10 = "power_10"

CONF_E1 = "energy_1"
CONF_E2 = "energy_2"
CONF_E3 = "energy_3"
CONF_E4 = "energy_4"
CONF_E5 = "energy_5"
CONF_E6 = "energy_6"
CONF_E7 = "energy_7"
CONF_E8 = "energy_8"
CONF_E9 = "energy_9"
CONF_E10 = "energy_10"

CONF_E_TOTAL = "energy_total"


CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(BL0910),


    cv.Optional(CONF_V):
        sensor.sensor_schema(device_class=DEVICE_CLASS_VOLTAGE,unit_of_measurement=UNIT_VOLT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(), 


    cv.Optional(CONF_I1):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(),   
    cv.Optional(CONF_I2):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(),   
    cv.Optional(CONF_I3):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(),  
    cv.Optional(CONF_I4):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_I5):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_I6):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_I7):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_I8):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_I9):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_I10):
        sensor.sensor_schema(device_class=DEVICE_CLASS_CURRENT,unit_of_measurement=UNIT_AMPERE,accuracy_decimals=3,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    
    
    cv.Optional(CONF_P1):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_P2):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(), 
    cv.Optional(CONF_P3):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P4):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P5):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P6):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P7):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P8):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P9):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
    cv.Optional(CONF_P10):
        sensor.sensor_schema(device_class=DEVICE_CLASS_POWER,unit_of_measurement=UNIT_WATT,accuracy_decimals=1,state_class=STATE_CLASS_MEASUREMENT).extend(),
        
        
    cv.Optional(CONF_E1):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E2):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E3):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E4):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E5):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E6):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E7):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E8):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E9):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   
    cv.Optional(CONF_E10):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   

    cv.Optional(CONF_E_TOTAL):
        sensor.sensor_schema(device_class=DEVICE_CLASS_ENERGY,unit_of_measurement=UNIT_KILOWATT_HOURS,accuracy_decimals=3,state_class=STATE_CLASS_TOTAL_INCREASING).extend(),   


}).extend(cv.polling_component_schema('60s')).extend(spi.spi_device_schema())


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield spi.register_spi_device(var, config)
    
    if CONF_V in config:
        conf = config[CONF_V]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_voltage_sensor(sens))
        

    if CONF_I1 in config:
        conf = config[CONF_I1]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_1(sens))

    if CONF_I2 in config:
        conf = config[CONF_I2]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_2(sens))

    if CONF_I3 in config:
        conf = config[CONF_I3]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_3(sens))
    
    if CONF_I4 in config:
        conf = config[CONF_I4]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_4(sens))

    if CONF_I5 in config:
        conf = config[CONF_I5]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_5(sens))

    if CONF_I6 in config:
        conf = config[CONF_I6]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_6(sens))

    if CONF_I7 in config:
        conf = config[CONF_I7]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_7(sens))

    if CONF_I8 in config:
        conf = config[CONF_I8]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_8(sens))

    if CONF_I9 in config:
        conf = config[CONF_I9]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_9(sens))

    if CONF_I10 in config:
        conf = config[CONF_I10]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_current_sensor_10(sens))


    if CONF_P1 in config:
        conf = config[CONF_P1]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_1(sens))

    if CONF_P2 in config:
        conf = config[CONF_P2]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_2(sens))

    if CONF_P3 in config:
        conf = config[CONF_P3]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_3(sens))

    if CONF_P4 in config:
        conf = config[CONF_P4]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_4(sens))

    if CONF_P5 in config:
        conf = config[CONF_P5]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_5(sens))

    if CONF_P6 in config:
        conf = config[CONF_P6]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_6(sens))

    if CONF_P7 in config:
        conf = config[CONF_P7]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_7(sens))

    if CONF_P8 in config:
        conf = config[CONF_P8]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_8(sens))

    if CONF_P9 in config:
        conf = config[CONF_P9]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_9(sens))

    if CONF_P10 in config:
        conf = config[CONF_P10]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_sensor_10(sens))


    if CONF_E1 in config:
        conf = config[CONF_E1]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_1(sens))

    if CONF_E2 in config:
        conf = config[CONF_E2]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_2(sens))

    if CONF_E3 in config:
        conf = config[CONF_E3]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_3(sens))

    if CONF_E4 in config:
        conf = config[CONF_E4]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_4(sens))

    if CONF_E5 in config:
        conf = config[CONF_E5]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_5(sens))

    if CONF_E6 in config:
        conf = config[CONF_E6]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_6(sens))

    if CONF_E7 in config:
        conf = config[CONF_E7]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_7(sens))

    if CONF_E8 in config:
        conf = config[CONF_E8]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_8(sens))

    if CONF_E9 in config:
        conf = config[CONF_E9]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_9(sens))

    if CONF_E10 in config:
        conf = config[CONF_E10]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energy_sensor_10(sens))

