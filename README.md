# 2° Parcial SPD

##### Lara Belén López
##### División 1G


# Sistema de incendios
## Circuito
<img src="./img/Circuito 2P SPD.png">

## Descripción
El circuito representa un sistema de alarma de incendios que al encenderlo con un control remoto infrarrojo detecta las variaciones de temperatura ambiente y activa un servo motor en caso de presentarse  un incendio.
Además, se muestra en un display LCD la estación del año segun la temperatura detectada y la misma en grados centígrados. En caso de incendio se muestra un mensaje de alarma.

## Funcionamiento

- Al presionar el botón rojo del control remoto IR se ingresa a la función principal "encenderApagarSistema()" que enciende una led verde para indicar que el sistema está activo y llama a otras funciones que muestran en el diplay LCD la estación del año y la temperatura detectada por el sensor de temperatura.
- Se puede modificar manualmente la temperatura utilizando el sensor. Esta variación es  detectada por la funcion "calcularEstacionDelAnio()" que dependiendo de la temperatura captada por el sensor de temperatura, imprime en el display LCD la estación del año y la temperatura actual.
- Si la temperatura detectada es mayor a 60°C se activa la alarma de incendios a través de la función "encenderAlarmaIncendio ()" que activa al servomotor, imprime un mensaje de alerta en el display LCD y hace titilar una led roja.
- El sistema se apaga presionando el botón "FUNC STOP" del control remoto IR.

## Link al proyecto
- [Proyecto Tinkercad](https://www.tinkercad.com/things/9lNbMEFC56V-fantabulous-albar/editel?sharecode=9MpAjigqtN6qLi0HSjE-tc-QiYiqYol5rxUR1EyyW_I "Proyecto Tinkercad")
