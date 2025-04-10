# ft_printf

## Descripción

El proyecto **ft_printf** consiste en reprogramar la función `printf()` de la biblioteca estándar de C (`libc`).

El prototipo de la función `ft_printf` es el siguiente:

```c
int ft_printf(const char *, ...);

```
## Conversiones realizadas:

- `%c`: Imprime un solo carácter.
- `%s`: Imprime una cadena de caracteres.
- `%p`: Imprime un puntero `void *` en formato hexadecimal.
- `%d`: Imprime un número decimal con signo (base 10).
- `%i`: Imprime un entero con signo (base 10).
- `%u`: Imprime un número decimal sin signo (base 10).
- `%x`: Imprime un número hexadecimal en minúsculas (base 16).
- `%X`: Imprime un número hexadecimal en mayúsculas (base 16).
- `%%`: Imprime el símbolo del porcentaje `%`.



## Archivos Fuente
### `ft_printf.c`
- Implementación principal de `ft_printf`.
- Gestiona los formatos mediante `ft_format` y usa `va_list`.

### `ft_puthex.c`
- Maneja `%x` y `%X`.
- Usa `ft_hex_len` y `ft_puthex_recursive`.

### `ft_putptr.c`
- Imprime punteros `%p` en formato `0x`.

### `ft_utils.c`
- Funciones auxiliares:
  - `ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putnbr_unsigned`.

### `main.c`
- Archivo de pruebas utilizado para validar el comportamiento de `ft_printf` frente al `printf` original.

## Compilación

1. **Generar la librería `libftprintf.a`**  
   Asegúrate de tener un `Makefile` correctamente configurado y ejecuta:

   ```bash
   make
   ```
Esto creará `libftprintf.a` en la raíz del proyecto.

2. **Compilar `main.c` junto a la librería**

```bash
cc main.c libftprintf.a
```


## Grade
100/100