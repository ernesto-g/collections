# Collections

Biblioteca de C que provee una arquitectura para almacenar y manipular elementos.
La misma consta de las siguientes entidades.

  - Linkedlist
  - Dictionary
  - Set
  - Collections

## Linkedlist

  - Permite almacenar punteros de cualquier tipo en una lista ordenada.
  - Provee funciones para agregar,modificar y quitar elementos.
  - Provee funciones para realizar operaciones de sort,map y filter.

## Dictionary

  - Permite almacenar punteros de cualquier tipo en un diccionario con claves de tipo cadena de caracteres.
  - Provee funciones para agregar,modificar y quitar elementos.
  - Provee funciones para obtener listas de claves y valores.

## Set

  - Permite almacenar punteros de cualquier tipo en un conjunto donde no se admiten repetidos.
  - Provee funciones para agregar,modificar y quitar elementos.

## Collections

  - Provee funciones útiles para manipular datos de listas, diccionarios y sets.

# Utilización

Incluir en el proyecto de Eclipse,dentro de la carpeta "src" del proyecto, la carpeta "collections" de este repositorio.
Luego incluir los archivos de cabecera para poder utilizar la biblioteca:

    #include "collections/Collections.h"
    #include "collections/Dictionary.h"
    #include "collections/LinkedList.h"
    #include "collections/Set.h"

# Ejemplos

Este repositorio es un proyecto de Eclipse el cual cuenta con un archivo Main.c en donde se invocan a funciones de ejemplos, ejemploX(). Cada funcion se encuentra es un archivo EjemploX.c
Puede descomentarse la funcion que se desee, compilar y ejecutar para probar los ejemplos.


# Documentación

La documetación se encuentra en la carpeta ["Documentation"](Documentation/html/index.html).




# Licencia

    Collections
    Copyright (C) 2021  Mauricio Davila
    Copyright (C) 2021  Ernesto Gigliotti

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

