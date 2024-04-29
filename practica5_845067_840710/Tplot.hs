-- 
--  Autores: Jorge Jaime Modrego   Nip: 845067 
--           Javier Julve Yubero   Nip: 840710
--              
--  Comentarios: En este fichero se encuentra el modulo Tplot
--        que contiene las funciones para pasar de 
--        una cadena de caracteres a una lista de
--        posiciones para poder representar el grafico
--

module Tplot where

import Turtle

-- Transforma una variable de tipo "Turtle" en una lista de variables de tipo "Position" (coordenadas x,y)
pos:: Turtle -> [Position]      
pos (x', y', x, y) = [x]

-- El primer paremetro es la posicion de la tortuga (coordenadas x,y y la direccion en la que mira )
-- El segundo parametro es la cadena de caracteres que se ha creado de forma recursiva con las reglas de un L-System
-- Devuelve una lista de posiciones (coordenadas x,y) que se utilizaran para dibujar el grafico
tplot :: Turtle -> String -> [Position]             
tplot t [] = pos t ++ []                            -- Si la cadena es vacia, devuelve la lista con todas las posiciones de la tortuga
tplot t (m:ms) = case m of                          -- Si la cadena no es vacia, se comprueba el primer caracter de la cadena.
    '>' -> pos t ++ tplot (moveTurtle t Forward) ms     -- si m es '>', entonces la tortuga avanza
    '+' -> tplot (moveTurtle t TurnRight) ms            -- si m es '+', entonces la tortuga gira a la derecha
    '-' -> tplot (moveTurtle t TurnLeft) ms             -- si m es '-', entonces la tortuga gira a la izquierda
    'F' -> pos t ++ tplot (moveTurtle t Forward) ms     -- si m es 'F', entonces la tortuga avanza
    'G' -> pos t ++ tplot (moveTurtle t Forward) ms     -- si m es 'G', entonces la tortuga avanza
    _   -> tplot t ms                                   -- si m es cualquier otro caracter, entonces no hace nada