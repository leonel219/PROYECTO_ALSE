#include <iostream>
#include "sensor.h"
#include "medicion.h"
#include "medicion.cpp"

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
    std::string crearTabla = "CREATE TABLE IF NOT EXISTS mediciones ("
                             "temperatura REAL, "
                             "humedad REAL, "
                             "precipitacion REAL, "
                             "intensidadLuz REAL, "
                             "fechaHora DATETIME DEFAULT CURRENT_TIMESTAMP, "
                             "minimo REAL, "
                             "promedio REAL, "
                             "maximo REAL);";
    rc = sqlite3_exec(db, crearTabla.c_str(), callback, 0, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al crear la tabla: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // Crear instancias de los sensores


    std::vector<Sensor*> sensores = {&Temperatura, &humedad, &precipitacion, &intensidadLuz};
    double obtenersensor(Temperatura)
    ValorT= getValor();
    double obtenersensor(Humedad)
    ValorH= getValor();   
    double obtenersensor(precipitación)
    ValorP= getValor();

    double obtenersensor(Intensidadluz)
    ValorI= getValor();

     // Esperar 5 segundos antes de la siguiente medición
     std::this_thread::sleep_for(std::chrono::seconds(5));
        }

    a.promtemperatura;
    b.promhumedad;
    c.promprecipitacion;
    d.promintensidad;

        // Insertar los datos de la medición en la base de datos
        medicion.insertarEnDB(db);

        std::cout << std::endl;
    }

    // Cerrar la conexión a la base de datos
    sqlite3_close(db);

    return 0;
}
