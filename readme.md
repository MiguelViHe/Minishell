# Minishell

## 📌 Descripción
**Minishell** es una implementación simplificada de un intérprete de comandos (shell) escrita en **C**, inspirada en *bash*. El objetivo del proyecto es comprender en profundidad cómo funciona un shell: gestión de procesos, señales, parsing de comandos, redirecciones y pipes.

Este proyecto es típico del currículo de **42**, y pone especial énfasis en el manejo correcto de memoria, errores y comportamiento fiel al shell real.

---

## ✨ Funcionalidades
- Prompt interactivo
- Ejecución de comandos mediante `$PATH`
- Soporte de **pipes (`|`)**
- Soporte completo de operadores lógicos: `&&` y `||` y prioridades con `()`
- Capacidad de ejecutar **subshells** dentro del shell principal
- **Redirecciones**:
  - `>` redirección de salida
  - `>>` append
  - `<` redirección de entrada
  - `<<` heredoc
- Variables de entorno (`$VAR`)
- Código de salida (`$?`)
- Builtins implementados:
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Manejo de señales (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`)

---

## 🛠️ Requisitos
- Sistema Linux o macOS
- `gcc`
- `make`
- Librerías estándar de C

---

## ⚙️ Compilación
Clona el repositorio y compila usando `make`:

```bash
git clone https://github.com/MiguelViHe/Minishell.git
cd Minishell
make
```

Para limpiar archivos objeto:

```bash
make clean
```

Para limpieza completa:

```bash
make fclean
```

Para recompilar desde cero:

```bash
make re
```

---

## ▶️ Ejecución
Una vez compilado, ejecuta:

```bash
./minishell
```

Ejemplo de uso dentro del shell:

```bash
echo "Hola mundo"
ls -l | grep .c
cat archivo.txt | wc -l
```

---

## 🧠 Detalles de implementación
- Parsing manual del input del usuario mediante automata de estados.
- Gestión de procesos con `fork`, `execve` y `wait`
- Pipes implementados con `pipe()`
- Redirecciones usando `dup2()`
- Manejo de señales con `signal` / `sigaction`
- Uso cuidadoso de memoria dinámica (sin leaks)

---

## 📂 Estructura del proyecto

```text
Minishell/
├── inc/
├── src/
├── submodules/
└── Makefile
```
---

## 🚫 Limitaciones
- Comportamiento simplificado respecto a bash real

---

## 📚 Aprendizajes
Este proyecto permite profundizar en:
- Programación de bajo nivel en C
- Procesos y señales en UNIX
- Diseño de parsers
- Arquitectura de sistemas

---

## 👤 Autores

**Miguel Vidal**  
GitHub: [MiguelViHe](https://github.com/MiguelViHe)
**Daniel Palacios**
GitHub: [Leined18](https://github.com/Leined18)
---

## 📄 Licencia
Este proyecto es únicamente con fines educativos.

