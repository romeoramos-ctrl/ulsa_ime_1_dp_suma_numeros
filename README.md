# Práctica 1: Suma de 5 números
## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

El programa pide 5 números al usuario, uno por uno, y los va sumando. Después de cada número muestra la suma acumulada hasta ese momento.
En la vida real serviría, por ejemplo, para sumar los gastos de una semana, las calificaciones de 5 materias o el total de una compra de 5 productos.

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y su objetivo. -->

**Entradas:**
1. `numero` (tipo `double`): cada uno de los 5 números que escribe el usuario. Su objetivo es ser sumado al total. Se pide 5 veces (lo controla `CANTIDAD = 5`).

**Salidas:**
1. `suma` (tipo `double`): la suma acumulada de los números ingresados. Se muestra después de cada número; la última vez que se imprime es la suma total de los 5.

## 3. Restricciones e invariante (Fase 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- Se deben ingresar exactamente 5 números.
- Cada entrada debe ser un número escrito con dígitos (por ejemplo `4`, `-2`, `3.5`). No se aceptan letras, palabras ni números romanos.
- Si se escribe algo que no es número, `cin` falla y el resto de las lecturas ya no funcionan (lo comprobé en las pruebas).

**Decisión sobre negativos y decimales** (¿los acepto? ¿por qué?):
Sí, acepto negativos y decimales porque uso `double`. Así el programa sirve para más casos (dinero con centavos, temperaturas bajo cero, etc.) y no solo para enteros positivos.

**Invariante** (¿qué es verdad después de cada vuelta del ciclo?):
Después de cada vuelta, `suma` es igual a la suma de los primeros `contador` números que ingresó el usuario, y `contador` nunca pasa de 5.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Números | Suma calculada a mano |
|---|---|---|
| 1 | 1, 2, 3, 4, 5 | 15 |
| 2 | 0, 0, 0, 0, 0 | 0 |
| 3 | -2, 5, -1, 3, 0 | 5 |

## 5. Receta en pseudocódigo (Fase 2)
# Receta: Suma de 5 números
1. Mostrar mensaje de bienvenida
2. suma 0
3. contador 0
4. MIENTRAS contador < 5 HACER
       Pedir al usuario el siguiente numero
       Leer el número
       suma ← suma + numero
       contador ← contador + 1
   FIN MIENTRAS
5. Mostrar el valor de suma 

**¿Probé mi receta a mano con un caso?** Sí, con el caso 1 (1 a 5): la suma fue 1, 3, 6, 10, 15.
**¿Tuve que corregirla?** Sí, al principio no había puesto que la suma empieza en 0 antes del ciclo.

## 6. Cómo compilar y ejecutar (Fase 3)

g++ -Wall -Wextra -std=c++17 main.cpp -o suma
./suma
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con un caso normal. -->

```
ingresa numero
1
suma: 1
ingresa numero
2
suma: 3
ingresa numero
3
suma: 6
ingresa numero
4
suma: 10
ingresa numero
5
suma: 15
```

## 8. Experimentos (Fase 3)

**Experimento A: ¿qué pasó al no inicializar `suma`?**
Cambié `double suma = 0.0;` por `double suma;`. Compiló sin advertencias y en mi prueba dio 15, pero fue suerte: una variable sin inicializar tiene "basura" (el valor que haya quedado en memoria). En otra computadora o con otras opciones de compilación puede dar un número raro. Por eso siempre hay que inicializar `suma` en 0.

**Experimento B (opcional): ¿qué pasó al usar `int` con 2.5?**
Cambié `numero` a `int` y escribí 2.5, 1, 1, 1, 1. El programa leyó solo el 2, el `.5` se quedó en la entrada y en la siguiente lectura `cin` falló. Desde ahí ya no leyó nada más: la suma se quedó en 2 en todas las vueltas y no me dejó escribir los otros números.

## 9. Tabla de pruebas (Fase 4)

| Caso | Números | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Del 1 al 5 | 1 a 5 | 15 | 15 | Sí |
| Todos ceros | 0 ×5 | 0 | 0 | Sí |
| Con negativos | -2, 5, -1, 3, 0 | 5 | 5 | Sí |
| Decimales | 0.5 ×5 | 2.5 | 2.5 | Sí |
| Todos iguales | 7 ×5 | 35 | 35 | Sí |
| Caso propio 1 | -1.5, -2.5, -3, -4, -5 | -16 | -16 | Sí |
| Caso propio 2 | 1000000, 2000000, 3000000, 4000000, 5000000 | 15000000 | 1.5e+07 | Sí (es el mismo valor, pero en notación científica) |

## 10. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Con números grandes la suma sale como `1.5e+07` en vez de `15000000`. | Se puede agregar `#include <iomanip>` y usar `std::fixed` al imprimir la suma. | Sí, con `fixed` se ve el número completo (con decimales). |
| 2 | Si escribo una letra (ej. `abc`), el programa deja de leer y repite la misma suma. | Se puede revisar `if (!(std::cin >> numero))`, limpiar con `cin.clear()` y `cin.ignore()`, y volver a pedir el número sin contarlo. | Pendiente de probar como reto. |

**Reto elegido (opcional):** Validar la entrada para que, si el usuario escribe algo que no es número, el programa muestre un mensaje y vuelva a pedirlo.

## 11. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Por qué el compilador no me avisó cuando quité la inicialización de `suma`, si tengo `-Wall -Wextra`? | Compilé con esas banderas y no salió ninguna advertencia; el resultado fue 15 de todos modos. |

## 12. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a usar un ciclo `while` con un contador, a acumular valores en una variable y la importancia de inicializarla. También vi que el tipo de dato (`int` o `double`) cambia lo que el programa puede leer.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Haría la tabla de pruebas antes de escribir el código, para saber desde el inicio qué casos debía cubrir (negativos, decimales, letras).

**¿Qué fue lo más difícil y cómo lo resolví?**
Entender qué pasaba cuando escribía algo que no era número o un decimal en un `int`. Lo resolví probando el programa con esas entradas y viendo que `cin` se "trababa" y ya no leía más.

**¿Qué pregunta me quedó sin responder?**
¿Cuál es la mejor forma de validar la entrada para que el programa no se trabe si el usuario se equivoca?

## 13. Lista de verificación antes de entregar (Fase 5)

- [x] Llené todas las secciones (no quedan `_____`)
- [x] Mi programa compila sin advertencias
- [x] Probé todos los casos de la tabla
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom