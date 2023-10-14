# Catch-a-Pigeon

## Integrantes

- Alva Sáenz, Rodrigo José

- Calle Huamantinco, Luis Eduardo

- Díaz Ingol, Jesús Stevan

- Rojas Castañeda, Ruth Camila

## Descripción del proyecto

El proyecto se centra en desarrollar un sistema de detección de plagas para áreas urbanas utilizando la plataforma Arduino y la programación en lenguaje C. El objetivo principal es crear una solución eficiente y automatizada para identificar la presencia de plagas, como insectos dañinos, roedores o cualquier otra amenaza para la salud pública y la vegetación en áreas urbanas.

## Objetivos

### Detección de Plagas en Tiempo Real: 
El principal objetivo del proyecto es implementar un sistema de detección de plagas que sea capaz de monitorear constantemente el entorno y detectar la presencia de plagas en tiempo real. Esto se logrará mediante sensores específicos que identificarán características asociadas con las plagas, como movimientos, sonidos o cambios en las condiciones ambientales.

### Comunicación con Arduino: 
Se desarrollará un sistema de comunicación entre los sensores y una placa Arduino para procesar los datos recopilados por los sensores. La Arduino será la unidad central de procesamiento que evaluará los datos y determinará si se ha detectado una plaga.

### Notificación a una Página Web: 
Cuando se detecte una plaga, el sistema enviará notificaciones automáticas a una página web dedicada al proyecto. Esto se logrará mediante la implementación de sockets TCP que permitirán la transferencia de datos en tiempo real entre Arduino y el servidor web. La página web servirá como plataforma central para visualizar y registrar todas las detecciones de plagas.

### Interfaz de Usuario Amigable: 
Se creará una interfaz de usuario en la página web que permitirá a los usuarios monitorear y analizar los datos de detección de plagas de manera efectiva. Los usuarios podrán ver informes, estadísticas y alertas sobre la presencia de plagas en su área urbana.

## Avances
### Primer avance
Primero intentamos adaptarnos a los materiales que tenemos, experimentando y haciendo mini trabajos para familiarizarnos con el esp32 y su IDE. El [Contador de 4 bits](https://github.com/pandadiestro/catch-a-pigeon/tree/main/Avance-Contador_4_bits) fue lo primero que realizamos.

![image](https://github.com/pandadiestro/catch-a-pigeon/assets/123672027/241e5d78-9728-4fef-8941-18d65eba9541)

### Segundo avance
Dentro de este [avance](https://github.com/pandadiestro/catch-a-pigeon/blob/main/espantapajaros.cpp), realizamos pruebas con el sensor PIR y conectamos el esp32 a la plataforma ThingSpeak para recibir información de los sensores.
