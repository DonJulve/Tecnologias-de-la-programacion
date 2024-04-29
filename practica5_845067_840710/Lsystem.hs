-- 
--  Autores: Jorge Jaime Modrego   Nip: 845067 
--           Javier Julve Yubero   Nip: 840710
--              
--  Comentarios: En este fichero se encuentra el modulo Lsystem
--        que contiene las reglas para crear los 
--        diferentes graficos de tortuga. Asi como las 
--        funciones para crear las cadenas de caracteres.
--

module Lsystem where

--Curva de Koch
rulesKoch :: Char -> String
rulesKoch 'F' = "F+F--F+F"
rulesKoch '+' = "+"
rulesKoch '-' = "-"
rulesKoch _ = ""

--Curva de Koch cuadrada
rulesKochC :: Char -> String
rulesKochC 'F' = "F+F-F-F+F"
rulesKochC '+' = "+"
rulesKochC '-' = "-"
rulesKochC _ = ""

--Koch Snowflake
rulesKochSnowflake :: Char -> String
rulesKochSnowflake 'F' = "F-F++F-F"
rulesKochSnowflake '+' = "+"
rulesKochSnowflake '-' = "-"
rulesKochSnowflake _ = ""

--Koch Anti-Snowflake
rulesKochAntiSnowflake :: Char -> String
rulesKochAntiSnowflake 'F' = "F+F--F+F"
rulesKochAntiSnowflake '+' = "+"
rulesKochAntiSnowflake '-' = "-"
rulesKochAntiSnowflake _ = ""

--Isla de Minkowski
rulesMinkowski :: Char -> String
rulesMinkowski 'F' = "F+F-F-FF+F+F-F"
rulesMinkowski '+' = "+"
rulesMinkowski '-' = "-"
rulesMinkowski _ = ""

--Triángulo de Sierpinsky
rulesSierpinsky :: Char -> String
rulesSierpinsky 'F' = "F-G+F+G-F"
rulesSierpinsky 'G' = "GG"
rulesSierpinsky '+' = "+"
rulesSierpinsky '-' = "-"
rulesSierpinsky _ = ""

--Sierpinsky Arrowhead
rulesSierpinskyArrowhead :: Char -> String
rulesSierpinskyArrowhead 'F' = "G-F-G"
rulesSierpinskyArrowhead 'G' = "F+G+F"
rulesSierpinskyArrowhead '+' = "+"
rulesSierpinskyArrowhead '-' = "-"
rulesSierpinskyArrowhead _ = ""

--Curva de Hilbert
rulesHilbert :: Char -> String
rulesHilbert 'F' = "-G>+F>F+>G-"
rulesHilbert 'G' = "+F>-G>G->F+"
rulesHilbert '+' = "+"
rulesHilbert '-' = "-"
rulesHilbert '>' = ">"
rulesHilbert _ = ""

--Curva de Gosper
rulesGosper :: Char -> String
rulesGosper 'F' = "F-G--G+F++FF+G-"
rulesGosper 'G' = "+F-GG--G-F++F+G"
rulesGosper '+' = "+"
rulesGosper '-' = "-"
rulesGosper _ = ""

--Alfombra de Sierpinski (Este grafico lo hemos añadido nosotros)
rulesAlfombra :: Char -> String
rulesAlfombra 'F' = "F+F-F-F-G+F+F+F-F"
rulesAlfombra 'G' = "GGG"
rulesAlfombra '+' = "+"
rulesAlfombra '-' = "-"
rulesAlfombra _ = ""

-- Se crean los diferentes patrones para crear cada una de las graficas de tortuga.
-- El primer parametro (Int) hace referencia al numero de la grafica de tortuga que se quiere crear
-- Devuelve la cadena resultante de aplicar las reglas de la grafica de tortuga
rules :: Int -> (Char -> String)
rules 1 x = rulesKoch x
rules 2 x = rulesKochC x
rules 3 x = rulesKochSnowflake x
rules 4 x = rulesKochAntiSnowflake x
rules 5 x = rulesMinkowski x
rules 6 x = rulesSierpinsky x
rules 7 x = rulesSierpinskyArrowhead x
rules 8 x = rulesHilbert x
rules 9 x = rulesGosper x
rules 10 x = rulesAlfombra x

-- Esta funcion aplica las reglas a anteriormente definidas. Estas se aplican de forma 
-- recursiva hasta que se llega al final de la cadena.
-- El primer parametro (Int) hace referencia al numero de la grafica de tortuga que se quiere crear
-- El segundo (String) es la cadena en la cual se le aplica las reglas
-- El tercer parametro (String) es la cadena de caracteres que se pasa recursivamente
-- Devuelve la cadena de caracteres tras aplicar las reglas a toda la cadena.
reglas :: Int -> String -> String -> String
reglas j (x:xs) y = reglas j xs ((rules j x) ++ y)  -- Patron que indica la recursividad
reglas j [] y = y                                   -- Patron que indica el final de la cadena  


-- Esta funcion es la encargada de crear las cadenas de caracteres tenienedo en cuenta el numero de iteraciones
-- El primer parametro (Int) hace referencia al numero de la grafica de tortuga que se quiere crear
-- El segundo parametro (String) es la cadena de caracteres que se pasa recursivamente. Inicial mente es el axioma
-- El tercer parametro (Int) es el numero de iteraciones que se quieren realizar
-- Devuelve la cadena de caracteres que se usara para crear el grafico de tortuga tras hacer todas las iteraciones
lsystem :: Int -> String -> Int -> String
lsystem j x 0 = x       -- Este patron indica que ya se han completado el numero de iteraciones deseadas y devuelve la cadena
lsystem  j "" _ = ""    -- Este patron indica que el numero de iteraciones es 0 y por lo tanto no se hace nada
lsystem j (x:xs) n = lsystem j (reglas j (x:xs) []) (n -1)  -- Patron que indica la recursividad y se le resta 1 a las iteraciones.
                                                                -- Se llama a la funcion "reglas" para aplicar los axiomas y reglas que
                                                                -- crearan la cadena de caracteres para el grafico de tortuga deseado.