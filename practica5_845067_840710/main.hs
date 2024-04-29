-- 
--  Autores: Jorge Jaime Modrego   Nip: 845067 
--           Javier Julve Yubero   Nip: 840710
--              
--  Comentarios: En este fichero se encuentra el "Main" del programa
--        que contiene las llamadas a las funciones que crean
--        los diferentes graficos tortugas.
--        Al ejecutar el programa, creara todas los .svg de los graficos de tortuga
--

import SVG(savesvg)
import Tplot
import Lsystem

main = do
    -- Graficos basicos
    savesvg "cuadrado" $ tplot (1, 90, (0,0), 0) ">+>+>+>"  -- Creacion de un cuadrado
    savesvg "triangulo" $ tplot (1, 120, (0,0), 0) ">+>+>"  -- Creacion de un triangulo
    savesvg "circulo" $ tplot (1,1, (0,0), 0) ">+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>"
    
    -- L-Systems
    savesvg "curva de koch" $ tplot (1,60, (0,0), 0) $ lsystem 1 "F" 3                  -- Creacion de la "curva de koch"
    savesvg "curva de koch cuadrada" $ tplot (1,90, (0,0), 0) $ lsystem 2 "F" 3         -- Creacion de la "curva de koch cuadrada"
    savesvg "Koch snowflake" $ tplot (1,60, (0,0), 0) $ lsystem 3 "F++F++F" 5           -- Creacion de "Koch snowflake"
    savesvg "Koch anti-snowflake" $ tplot (1,60, (0,0), 0) $ lsystem 4 "F++F++F" 5      -- Creacion de "Koch anti-snowflake"
    savesvg "Isla de Mikowski" $ tplot (1,90, (0,0), 0) $ lsystem 5 "F+F+F+F" 3         -- Creacion de la "Isla de Mikowski"
    savesvg "Triángulo de Sierpinsky" $ tplot (1,-120, (0,0), 0) $ lsystem 6 "F-G-G" 5  -- Creacion del "Triángulo de Sierpinsky"
    savesvg "Sierpinsky Arrowhead" $ tplot (1,-60, (0,0), 0) $ lsystem 7 "F" 7          -- Creacion de "Sierpinsky Arrowhead"
    savesvg "Curva de Hilbert" $ tplot (1,-90, (0,0), 0) $ lsystem 8 "F" 4              -- Creacion de la "Curva de Hilbert"
    savesvg "Curva de Gosper" $ tplot (1,-60, (0,0), 0) $ lsystem 9 "F" 3               -- Creacion de la "Curva de Gosper"
    savesvg "Alfombra de Sierpinski" $ tplot (1,90, (0,0), 0) $ lsystem 10 "F" 4        -- Creacion de la "Alfombra de Sierpinski"