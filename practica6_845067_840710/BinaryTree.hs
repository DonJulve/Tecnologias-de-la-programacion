-----------------------------------------------------------------------------
-- Fichero: BinaryTree.hs de la práctica 6
-- Autores: Jorge Jaime Modrego(845067) y Javier Julve Yubero(840710)
-- Fecha: Mayo 2024
-----------------------------------------------------------------------------
module BinaryTree where

import Data.List

--Dato de tipo tree
data Tree a = Vacio | Leaf a (Tree a) (Tree a)

-- Función que genera un árbol vacío, sin ningún elemento
empty :: Tree a 
empty = Vacio

-- Función que devuelve un árbol que consta de una sola hoja que contiene el elemento a
leaf :: a -> Tree a
leaf a = Leaf a (empty) (empty)

-- Función que crea un árbol que contiene como raíz el elemento x con un hijo izquierod lc y un hijo derecho rc,
-- tanto el hijo izquierdo como el derecho son nodos de árbol, no elementos del tipo de dato genérico
tree :: a -> Tree a -> Tree a -> Tree a 
tree x Vacio Vacio = Leaf x (empty) (empty)
tree x Vacio rc  = Leaf x (empty) (rc)
tree x lc Vacio = Leaf x (lc) (empty)
tree x lc rc = Leaf x (lc) (rc)

-- Función que devuelve el número de eleemntos del árbol
size :: Tree a -> Integer
size Vacio = 0
size (Leaf a Vacio Vacio) = 1
size (Leaf a (lc) (rc)) = 1 + size lc + size rc

-- Función que dependiendo el nivel de la hoja, la muestra con su tabulación correspondiente
tab :: Integer -> String
tab 0 = ""
tab x = "  " ++ (tab (x-1)) 

-- Función para mostrar graficamente un árbol
showT :: (Show a) => Tree a -> Integer -> String 
showT (Vacio) x = "()"
showT (Leaf a (Vacio) (Vacio)) x = show a
showT (Leaf a (lc) (rc)) x = show a ++ "\n" ++  tab x ++ "|- " ++ showT (lc) (x + 1) ++ "\n" ++  tab x ++ "|- " ++ showT (rc) (x + 1)

instance (Show a) => Show (Tree a) where
  show a = showT a 0 

-- Función que añade el elemento x al árbol, devolviendo el árbol resultante
add :: Ord a => Tree a -> a -> Tree a
add Vacio x = leaf x
add (Leaf y lc rc) x
    | x < y    = Leaf y (add lc x) rc
    | otherwise = Leaf y lc (add rc x)

-- Función que construye un árbol binario de búsqueda, comenzando con uno vacío e insertando
-- en orden los elementos de la lista xs
build :: Ord a => [a] -> Tree a 
build xs = buildAux xs empty
  where
    buildAux [] t = t
    buildAux (x:xs) t = buildAux xs (add t x)

-- Función que construye un árbol equilibrado, ordenando la lista y dividiéndola en dos por la mediana
buildBalanced :: Ord a => [a] -> Tree a 
buildBalanced [] = Vacio
buildBalanced xs = Leaf x (buildBalanced izq) (buildBalanced der)
  where
    sorted = sort xs
    (izq, x:der) = splitAt (length xs `div` 2) sorted

-- Función que devuelve una lista con todos los elementos del árbol recorrido en preorden
preorder :: Tree a -> [a]
preorder Vacio = []
preorder (Leaf x lc rc) = x : preorder lc ++ preorder rc

-- Función que devuelve una lista con todos los elementos del árbol recorrido en postorden
postorder :: Tree a -> [a]
postorder Vacio = []
postorder (Leaf x lc rc) =  postorder lc ++ postorder rc ++ [x]

-- Función que devuelve una lista con todos los elementos del árbol recorrido en orden
inorder :: Tree a -> [a]
inorder Vacio = []
inorder (Leaf x lc rc) = inorder lc ++ [x] ++ inorder rc

-- Función que construye un árbol equilibrado a partir de otro cualquiera
balance :: Ord a => Tree a -> Tree a 
balance Vacio = (empty)
balance t = buildBalanced (inorder t)

-- Función que busca en el árbol los elementos que están entre los valores xmin y xmax y los devuelve en una lista
between :: (Ord a, Num a) => Tree a -> a -> a -> [a]
between Vacio _ _ = []
between  (Leaf x lc rc) xmin xmax
  | x < xmin = between rc xmin xmax
  | x > xmax = between lc xmin xmax
  | otherwise = x : between lc xmin x ++ between rc (x+1) xmax