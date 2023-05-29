#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "sensor.h"
#include "sqlite3.h"

// Función de callback para ejecutar las consultas SQLite
int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    return 0;
}

int main() {
    // Crear conexión a la base de datos
    sqlite3* db;
    int rc = sqlite3_open("mediciones.db", &db);
    if (rc) {
        std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    // Crear tabla para las mediciones si no existe
    std::string crearTabla = "CREATE TABLE IF NOT EXISTS mediciones (min REAL, promedio REAL, max REAL, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
    rc = sqlite3_exec(db, crearTabla.c_str(), callback, 0, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al crear la tabla: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // Crear instancias de los sensores
    Temperatura temperaturaSensor;
    Humedad humedadSensor;
    Precipitacion precipitacionSensor;
    IntensidadLuz intensidadLuzSensor;

    std::vector<Sensor*> sensores = {&temperaturaSensor, &humedadSensor, &precipitacionSensor, &intensidadLuzSensor};

    // Calcular el promedio cada minuto durante 10 minutos
    const int numMedicionesPorMinuto = 12;
    const int numMinutos = 10;
    for (int minuto = 1; minuto <= numMinutos; minuto++) {
        std::cout << "Minuto " << minuto << std::endl;

        // Realizar mediciones cada 5 segundos
        for (int i = 0; i < numMedicionesPorMinuto; i++) {
            std::cout << "Medición " << i + 1 << std::endl;

            // Tomar mediciones de cada sensor
            for (Sensor* sensor : sensores) {
                sensor->tomarMedicion();
                std::cout << "Valor: " << sensor->getValor() << std::endl;
            }

            // Esperar 5 segundos antes de la siguiente medición
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        // Calcular el mínimo, promedio y máximo de las mediciones
        double sumaTotal = 0.0;
        double minimo = sensores[0]->getValor();
        double maximo = sensores[0]->getValor();
        for (Sensor* sensor : sensores) {
            double valor = sensor->getValor();
            sumaTotal += valor;
            if (valor < minimo) {
                minimo = valor;
            }
            if (valor > maximo) {
                maximo = valor;
            }
        }
        double promedio = sumaTotal / sensores.size
