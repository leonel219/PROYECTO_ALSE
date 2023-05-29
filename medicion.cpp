#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "sensor.h"
#include "medicion.h"
 
    double Temperatura::promtemperatura(const Temperatura ){

    // Calcular el promedio cada minuto durante 10 minutos
    const int numMedicionesPorMinuto = 12;
    const int numMinutos = 10;
    for (int minuto = 1; minuto <= numMinutos; minuto++) {
       

        // Realizar mediciones cada 5 segundos
        for (int i = 0; i < numMedicionesPorMinuto; i++) {
         

            // Tomar mediciones de cada sensor
            for (Sensor* sensor : sensores) {
                sensor->tomarMedicion();
                
            }

            // Esperar 5 segundos antes de la siguiente medición
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        // Calcular el promedio de las mediciones
        double sumaTotal = 0.0;
        for (Sensor* sensor : sensores) {
            sumaTotal += sensor->getValor();
        }
        double promedio = sumaTotal / sensores.size();
       
    }

    return promedio;
}
    double Humedad::promhumedad(const Humedad ){

    // Calcular el promedio cada minuto durante 10 minutos
    const int numMedicionesPorMinuto = 12;
    const int numMinutos = 10;
    for (int minuto = 1; minuto <= numMinutos; minuto++) {
           

        // Realizar mediciones cada 5 segundos
        for (int i = 0; i < numMedicionesPorMinuto; i++) {
               

            // Tomar mediciones de cada sensor
            for (Sensor* sensor : sensores) {
                sensor->tomarMedicion();
                   
            }

            // Esperar 5 segundos antes de la siguiente medición
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        // Calcular el promedio de las mediciones
        double sumaTotal = 0.0;
        for (Sensor* sensor : sensores) {
            sumaTotal += sensor->getValor();
        }
        double promedio = sumaTotal / sensores.size();
           
    }

    return promedio;
}
    double IntensidadLuz::promintensidadluz(const Temperatura ){

    // Calcular el promedio cada minuto durante 10 minutos
    const int numMedicionesPorMinuto = 12;
    const int numMinutos = 10;
    for (int minuto = 1; minuto <= numMinutos; minuto++) {
           

        // Realizar mediciones cada 5 segundos
        for (int i = 0; i < numMedicionesPorMinuto; i++) {
               

            // Tomar mediciones de cada sensor
            for (Sensor* sensor : sensores) {
                sensor->tomarMedicion();
                   
            }

            // Esperar 5 segundos antes de la siguiente medición
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        // Calcular el promedio de las mediciones
        double sumaTotal = 0.0;
        for (Sensor* sensor : sensores) {
            sumaTotal += sensor->getValor();
        }
        double promedio = sumaTotal / sensores.size();
           
    }

    return promedio;
}
    double Precipitacion ::promprecipitacion (const Temperatura ){

    // Calcular el promedio cada minuto durante 10 minutos
    const int numMedicionesPorMinuto = 12;
    const int numMinutos = 10;
    for (int minuto = 1; minuto <= numMinutos; minuto++) {
           

        // Realizar mediciones cada 5 segundos
        for (int i = 0; i < numMedicionesPorMinuto; i++) {
               

            // Tomar mediciones de cada sensor
            for (Sensor* sensor : sensores) {
                sensor->tomarMedicion();
                   
            }

            // Esperar 5 segundos antes de la siguiente medición
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        // Calcular el promedio de las mediciones
        double sumaTotal = 0.0;
        for (Sensor* sensor : sensores) {
            sumaTotal += sensor->getValor();
        }
        double promedio = sumaTotal / sensores.size();
           
    }

    return promedio;
}
