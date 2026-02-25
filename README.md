# Pulsador-Inalambrico

## Introducción

Este proyecto es un SWITCH ON/OFF inalámbrico basado en ESP-01, para el manejo de un juguete a distancia.

[![](https://img.plantuml.biz/plantuml/dsvg/PKyz2i8m5DxVAHxTKx6ZWvI27HmQ4RVY499d3JH9JLvEvX6yc4Ge5Do-V_ZQn2foTZE0zKpneJHXrGKE7kMmatrVeKhOoTl-Fs084ysajVsyVym54zPy0r1QA70yEPj2l1VUeCZBHbe1rj5EJwwFE5v9qy95E-15lJ8nbMsZE2JOk0BFUIekG4lUb0zV)](https://editor.plantuml.com/uml/PKyz2i8m5DxVAHxTKx6ZWvI27HmQ4RVY499d3JH9JLvEvX6yc4Ge5Do-V_ZQn2foTZE0zKpneJHXrGKE7kMmatrVeKhOoTl-Fs084ysajVsyVym54zPy0r1QA70yEPj2l1VUeCZBHbe1rj5EJwwFE5v9qy95E-15lJ8nbMsZE2JOk0BFUIekG4lUb0zV)

El emisor posee un botón de encendido y apagado del juguete, y un selector de modo entre PULSADOR y LLAVE:
- El modo PULSADOR enciende el juguete solo cuando se mantiene presionado el botón
- El modo LLAVE cambia el estado entre ON/OFF con un solo toque del botón

## Programación de los ESP-01
Para la programación de los ESP-01 se utiliza Platformio IDE.
Los archivos de código del Emisor y del Receptor se encuentran en las carpetas:
- Emisor_modo_pulsador
- Receptor

## Circuitos 
Los circuitos de emisión y recepción para este proyecto se encuentran en esta sección. Están diseñados utilizando:
- Batería de litio
- Módulo de carga
- Reguladores de 3.3V con baja caída de tensión MCP1700
- ESP01
De todas maneras se podría reemplazar el MCP1700 por uno similar (XC6206, BA33BC0, etc.), al igual que el ESP-01 por otro módulo que también esté basado en el ESP8266.

### Circuito del Emisor
![Circuito_Emisor](https://github.com/user-attachments/assets/1cabc958-4f55-4b9e-a1a9-92c4ed5a54d6)

### Circuito del Receptor 
![Circuito_Receptor](https://github.com/user-attachments/assets/c992bed3-6ac1-4c99-918b-60443d1fe238)
El optoacoplador U2 y el transistor Q1 que manejan al juguete se pueden alternar por un relé.
