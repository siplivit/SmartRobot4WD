/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sensor.h
 * Author: vsiplichuk <vsiplichuk at atncorp.com>
 *
 * Created on July 18, 2017, 5:21 PM
 */

#ifndef SENSOR_H
#define SENSOR_H

#define CLASS_SENSOR 0
#define CLASS_ACCELEROMETER 1
#define CLASS_MAGNETOMETER 2
#define CLASS_GYROSCOPE 3

enum sensor_type
{
    NOTDEFINED = 0,
    TEMPERATURE,
    HUMIDITY,
    PRESSURE,
    ACCELEROMETER,
    GYROSCOPE,
    MAGNETOMETER
};

typedef struct sensor_drv_t_{
    int (*init)(void);
    int (*start)(void);
    int (*stop)(void);
    int (*read_data)(void);
}sensor_drv_t;

class Sensor
{
private:
protected:
    int classID;
    sensor_type type;
    std::string name;
    sensor_drv_t drv;
    int period;
public:
    Sensor();
    Sensor(int _id, int _type; std::string _s);
    
    void setType(const sensor_type& v);
    void setId(const int& value);
    void setName(const std::string& s);
    const sensor_type& getType(void);
    const int& getId(void);
    const std::string& getName(void);
    bool operator< (const Sensor& other) const;
    virtual char *classname() { return (char *) "sensor"; }
    
    virtual void attachDrv(sensor_drv_t *newDrv);
    virtual int detachDrv(void);
    
    virtual int sensorInit(void);
    virtual int sensorStart(void);
    virtual int sensorStop(void);
    
    virtual void setData(double) = 0;
    virtual double getData(void) = 0;
    
    virtual ~Sensor();
};

class Accelerometer: public Sensor
{
private:
protected:
public:
    Accelerometer(int _id, int _type; std::string _s);
    void setData(double);
    double getData(void);
};

class Magnetometer: public Sensor
{
private:
protected:
public:
    Magnetometer(int _id, int _type; std::string _s);
    void setData(double);
    double getData(void);
};

#endif /* SENSOR_H */

