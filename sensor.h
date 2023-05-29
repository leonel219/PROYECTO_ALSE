#ifndef SENSORES_H
#define SENSORES_H

class Sensor {
protected:
    double min;
    double max;
    double valor;

public:
    Sensor(double min, double max) {
        this->min = min;
        this->max = max;
        this->valor = 0.0;
    }

    virtual void tomarMedicion() = 0;

    double getValor() {
        return valor;
    }

    void setValor(double valor) {
        if (valor >= min && valor <= max) {
            this->valor = valor;
        }
    }
};

class Temperatura : public Sensor {
public:
    Temperatura() : Sensor(-10.0, 45.0) {}

    void tomarMedicion() {
      
        double valorMedido = obtenerValorDesdeSensor();
        setValor(valorMedido);
    }

    double obtenerValorDesdeSensor() {
       //generamos un valor aleatorio
        return (min + (max - min) * rand() / (RAND_MAX + 1.0));
    }
};

class Humedad : public Sensor {
public:
    Humedad() : Sensor(0.0, 100.0) {}

    void tomarMedicion() {
        // Simulamos la obtencion del valor
        double valorMedido = obtenerValorDesdeSensor();
        setValor(valorMedido);
    }

    double obtenerValorDesdeSensor() {
        // generaremos un valor aleatorio dentro del rango permitido
        return (min + (max - min) * rand() / (RAND_MAX + 1.0));
    }
};

class Precipitacion : public Sensor {
public:
    Precipitacion() : Sensor(0.0, 50.0) {}

    void tomarMedicion() {
        // Simular la obtención del valor de precipitación desde el sensor
        double valorMedido = obtenerValorDesdeSensor();
        setValor(valorMedido);
    }

    double obtenerValorDesdeSensor() {
        // generaremos un valor aleatorio dentro del rango permitido
        return (min + (max - min) * rand() / (RAND_MAX + 1.0));
    }
};

class IntensidadLuz : public Sensor {
public:
    IntensidadLuz() : Sensor(0.0, 2000.0) {}

    void tomarMedicion() {
        // Simular la obtención del valor de intensidad de luz desde el sensor
     
        double valorMedido = obtenerValorDesdeSensor();
        setValor(valorMedido);
    }

    double obtenerValorDesdeSensor() {
        
        // Generamos un valor aleatorio
        return (min + (max - min) * rand() / (RAND_MAX + 1.0));
    }
};

#endif // SENSORES_H
