module BinaryTree where

data BinaryTree a = Empty | Node a (BinaryTree a) (BinaryTree a) -- El arbol puede ser vacio o tener un nodo con 2 hijos

vacio::BinaryTree a  -- Defininimos un arbol vacio
vacio = Empty

-- Una hoja por definicion es un arbol que no tiene ningun hijo (es decir tiene hijos vaciod)
leaf::a->BinaryTree a
leaf x = Node x Empty Empty


-- Esta función tiene parametros de tipo "BinaryTree" y devuelve el arbol resultante de la union de estosl 
-- El primero es el nodo raiz
-- El segundo y tercero son el hijo izquierdo y derecho respectivamente.
tree::a->BinaryTree a->BinaryTree a->BinaryTree a
tree a Empty Empty = Node a Empty Empty     
tree a Empty b = Node a Empty b
tree a b Empty = Node a b Empty
tree a b c = Node a b c


-- Se le pasa una paramentro de tipo "BinaryTree" y devuelve el numero de nodos que tiene.
size::BinaryTree a->Integer
size Empty = 0                              -- si el arbol es vacio no hay nada que sumar
size (Node a Empty Empty) = 1               -- si es una "hoja" sumamos 1 ( caso base )
size (Node a Empty b) = 1 + size b          -- si tiene un hijo a la derecha accedemos recursivamente
size (Node a b Empty) = 1 + size b          -- si tiene un hijo a la izquierda accedemos recursivamente
size (Node a b c) = 1 + size b + size c     -- si tiene 2 hijos primero accedemos a uno y luego al otro de forma recursiva


-- Se pasa un tipo de dato
add::(Ord a) => BinaryTree a -> a -> BinaryTree a
add Empty a = leaf a                        -- si es vacio añadimos una nueva hoja (caso base)
add (Node a b c) x                          
    | a == x = (Node a b (add c x))         -- si el valor del nodo es igual al valor del arbola introducir bajamos por la derecha
    | a < x = (Node a b (add c x))          -- si el valor del nodo es menor que el del arbol a introducir a bajamos por la derecha 
    | otherwise = Node a (add b x) (c)      -- si el valor del nodo es mayor que el del arbol a itroducir bajamos por la izquierda        


-- Los argumentos de esta funcion son:
--      Una lista con los elementos a introducir
--      Un dato de tipo BinaryTree que se pasa recursivamente para la creacion del arbol
-- Esta funcion devuelve un arbol con todos los elementos de la lista genérica
buildAux::(Ord a) => [a] -> BinaryTree a -> BinaryTree a
buildAux [] a = a                               -- No hay mas elementos que introducir (caso base)
buildAux (x:xs) a = buildAux xs (add a x)       -- Recirsivamente se va creando el arbol.


-- Dado un lista generica devuelve un arbol binario con los elementos de esa lista
build::(Ord a) => [a] -> BinaryTree a
build [] = Empty                -- Si la lista es vacia devolvemos un arbol vacio
build x = buildAux x Empty      -- Se llama a la funcion "buildAux" para crear todo el arbol

-- Dado un arbol y un entero ( es to es opcional ) devuelve los elementos que tiene el arbol
-- siguiendo el formato del guion de la practica
imprimir::(Show a) => BinaryTree a -> Integer -> String
imprimir Empty x = "<>"                     -- Si es vacia
imprimir (Node a Empty Empty) x = show a    -- Si los hijos son "vacios" devolvemos solo el nodo
imprimir (Node a b c) x = show a ++ ['\n'] ++ (tabulaciones x) ++ ("|-") ++ imprimir b (x+1) ++ ['\n'] ++ (tabulaciones x) ++ ("|-") ++ imprimir c (x + 1)
instance (Show a) => Show (BinaryTree a) where
    show a = imprimir a 0   -- El entero opcional introducirlo por este "Condicion"


-- Se le pasa el numero de tabulacion que se necesitan y devuelve una cadena con el numero de tabulaciones indicado por el Integer
tabulaciones::Integer->String
tabulaciones 0 = ""                             -- Caso base
tabulaciones x = "  " ++ tabulaciones (x-1)     -- Recursivamente se escriben tabulaciones


-- Dado un lista con los elementos a introcir devuelve un arbol binario balanceado con los componentes de esta lista
buildBalanced::(Ord a) => [a] -> BinaryTree a
buildBalanced [] = Empty        -- Si es vacio devuelve un arbol vacio
buildBalanced [x] = leaf x      -- caso base
buildBalanced x = tree (x!!(div (length x) 2)) (buildBalanced (take (div (length x) 2) x)) (buildBalanced (drop ((div (length x) 2) + 1) x))
-- El nodo raiz del arbol sera el elemento que se encuentra en el centro de toda lista. El hijo de izquierdo sera el elemento que se
-- encuentra en la posicion del medio de entre el incio y el medio de toda la lista. Con hijo derecho sucedera de fornma parecida


-- Se le pasa un parametro de tipo "BinaryTree" y devuelve una cadena con los elementos del arbol en preorder
-- El orden en preorder de un arbol sencillo ( un nodo raiz y nodos hijos ) seria: 
-- primero el nodo raiz, luego el hijo izquierdo y luego el derecho
preorder::(Ord a) => BinaryTree a -> [a]
preorder Empty = []                                         -- Si es un arbol vacio devolvemos una lista vacia
preorder (Node a Empty Empty) = [a]                         -- Si es vacio devolvemos la lista ( caso base )
preorder (Node a b c) = [a] ++ preorder b ++ preorder c     -- Si no es vacia accedemos a los hijos en preorder


-- Se le pasa un parametro de tipo "BinaryTree" y devuelve una cadena con los elementos del arbol en postorder
-- El orden en preorder de un arbol sencillo ( un nodo raiz y nodos hijos ) seria: 
-- primero el hijo izquierdo, luego el derecho y luego el nodo raiz
postorder::(Ord a) => BinaryTree a -> [a]
postorder Empty = []                                        -- Si es un arbol vacio devolvemos una lista vacia
postorder (Node a Empty Empty) = [a]                        -- Si es vacio devolvemos la lista ( caso base )
postorder (Node a b c) = postorder b ++ postorder c ++ [a]  -- Si no es vacia accedemos a los hijos en postorder


-- Se le pasa un parametro de tipo "BinaryTree" y devuelve una cadena de caracteres con los datos del arbol en inorder
-- El orden en preorder de un arbol sencillo ( un nodo raiz y nodos hijos ) seria: 
-- primero el hijo izquierdo, luego el nodo raiz y luego el hijo izquierdo
inorder::(Ord a) => BinaryTree a -> [a]
inorder Empty = []                                      -- Si es un arbol vacio devolvemos una lista vacia
inorder (Node a Empty Empty) = [a]                      -- Si es vacio devolvemos la lista ( caso base )
inorder (Node a b c) = inorder b ++ [a] ++ inorder c    -- Si no es vacia accedemos a los hijos en inorder


-- Se le pasa un paremtro de tipo "BinaryTree" y devuelve otro "BinaryTree" pero balanceado (altura minima)
balance::(Ord a) => BinaryTree a -> BinaryTree a
balance Empty = Empty                   -- Si es vacio devolvemos otro vacio
balance a = buildBalanced (inorder a)   -- Si no llamamos a buildBalanced pasando la cadena de texto inorder


-- Dado un arbol y los datos de minimo y maximo devuele todos 
between::(Ord a) => BinaryTree a -> a -> a -> [a]
between Empty a b = []              -- Si el arbol es vacio devuelve un lista vacia
between (Node a Empty Empty) x y    -- Si tiene hijos vacios
        | a >= x && a <= y = [a]        -- Añade en la lista si el elemento cumple la condicion
        | otherwise = []                -- Sino no mete nada

between (Node a b c) x y            -- Si el el arbol tiene hijos
        | a < x = between c x y         -- Baja por la derecha  
        | a > y = between b x y         -- Baja por la izquierda
        | a == x = between c x y ++ [a] -- Baja por la derecha y escribe el elemento en la lista
        | a == y = between b x y ++ [a] -- Baja por la izquierda y escribe el elemento en la lista
        | otherwise = [a] ++ between b x y ++ between c x y