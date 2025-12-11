This project has been created as part
of the 42 curriculum by ldemaill.

This project aims to recreate a function with behavior similar to that of the original printf function.

For use this function you need to use make to create libftprinf.a and compile them together.

## Project

My `ft_printf` handles the following conversions:

* **Characters & Strings:** `%c`, `%s`
* **Integers:** `%d`, `%i`, `%u`
* **Hexadecimal:** `%x`, `%X`, `%p` (memory address)
* **Escape:** `%%`
* **Unknow variant** Will be treated like a string (similar as the original)
* **NULL** Will doesn't display anything but return -1 Value as count

## Compilation

The project contains a `Makefile` with the usual rules:

* `make`: Compiles the `libftprintf.a` library with flags (-Wall -Wextra -Werror -MMD -MP), make also *.o files, create dependency (*.d) and check the Header or Makefile modification.

* `make clean`: Removes object files (`.o`).

* `make fclean`: Removes objects, the library, the dependancy (*.d) and if necessary a.out.

* `make re`: Recompiles everything from scratch.

## Testing

I tested my function with my own main function, but also with Francinette.

main test example:
```c

#include <stdio.h>

int	main(void)
{
	const char		*s;
	unsigned int	u;
	int				d;
	void			*p;
	int				count;
	int				y;

	s = "%%%%";
	u = 548763544;
	d = -92233724;
	p = &d;
	y = d;
	ft_printf("******* vrai printf *******\n");
	count = printf("s=%s\nu=%u\nd=%d\nmem=%p\n", s, u, d, p);
	printf("           %d\n", count);
	ft_printf("***************************\n");
	ft_printf("\n");
	ft_printf("****** mon ft_printf ******\n");
	count = ft_printf("s=%s\nu=%u\nd=%d\nmem=%p\n", s, u, d, p);
	printf("           %d\n", count);
	ft_printf("***************************\n");
	return (0);
}
```
For this project, I used the 42 method to learn the concepts I was missing (peer-to-peer learning).