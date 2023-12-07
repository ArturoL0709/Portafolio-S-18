
"""" Arturo López García A01276405
Proyecto integrador de pensamiento computacional para la ingeniería. El proyecto trata de una tienda 
de videojuegos llamada GamePlanet que se dedica a vender consolas de diferentes marcas """


#Primero declaramos nuestras 3 listas base que serviran para todas las funciones del programa
inventario = [] # lista vacía para almacenar los productos
vendedores = ["Arturo"] # lista vacía para almacenar los vendedores
ventas = [] # lista vacía para almacenar las ventas



"""
Esta función solicita al usuario información sobre un producto (modelo, nombre y cantidad)
 y luego crea un diccionario que contiene esta información. 
Luego, este diccionario se agrega a la lista inventario.
"""

def registrar_producto():
    modelo = input("Ingrese el modelo del producto: ")
    nombre = input("Ingrese el nombre del producto: ")
    cantidad = int(input("Ingrese la cantidad en existencia: "))
    producto = {"modelo": modelo, "nombre": nombre, "cantidad": cantidad}
    inventario.append(producto)
    print("Producto registrado correctamente.")

"""
Esta función solicita al usuario el nombre de un vendedor y lo agrega a la lista vendedores.
"""  
def registrar_vendedor():
    nombre = input("Ingrese el nombre del vendedor: ")
    vendedores.append(nombre)
    print("Vendedor registrado correctamente.")

"""
Esta función solicita al usuario información sobre una venta (modelo del producto, nombre del vendedor y cantidad vendida). 
Luego, busca en la lista inventario el producto correspondiente al modelo ingresado y reduce su cantidad en la cantidad vendida. 
Además, crea un diccionario que contiene la información de la venta (modelo, vendedor y cantidad) y lo agrega a la lista ventas.
"""  
def registrar_venta():
    modelo = input("Ingrese el modelo del producto vendido: ")
    vendedor = input("Ingrese el nombre del vendedor: ")
    cantidad = int(input("Ingrese la cantidad vendida: "))
    
    # Actualizar inventario
    for producto in inventario:
        if producto["modelo"] == modelo:
            producto["cantidad"] -= cantidad
            break
    
    # Registrar venta
    venta = {"modelo": modelo, "vendedor": vendedor, "cantidad": cantidad}
    ventas.append(venta)
    print("Venta registrada correctamente.")

"""
Esta función solicita al usuario información sobre la llegada de un producto al almacén (modelo y cantidad). 
Si el producto ya existe en la lista inventario, se actualiza la cantidad. 
De lo contrario, se solicita el nombre del producto y se crea un diccionario con la información completa del producto
que luego se agrega a la lista inventario.
"""  
    
def registrar_llegada():
    modelo = input("Ingrese el modelo del producto que llegó: ")
    cantidad = int(input("Ingrese la cantidad que llegó: "))
    
    # Actualizar inventario
    for producto in inventario:
        if producto["modelo"] == modelo:
            producto["cantidad"] += cantidad
            break
    else:
        # Si el modelo no existe en el inventario, lo agregamos
        nombre = input("Ingrese el nombre del producto: ")
        producto = {"modelo": modelo, "nombre": nombre, "cantidad": cantidad}
        inventario.append(producto)
        
    print("Llegada registrada correctamente.")
    
"""
Esta función imprime una lista de todos los productos en el inventario, mostrando su modelo, nombre y cantidad.
"""  
def consultar_inventario():
    print("Inventario:")
    for producto in inventario:
        print(f"Modelo: {producto['modelo']} - Nombre: {producto['nombre']} - Cantidad: {producto['cantidad']}")

"""
Esta función imprime una lista de todas las ventas registradas, mostrando el modelo del producto, el nombre del vendedor y la cantidad vendida.
"""
        
def consultar_ventas():
    print("Ventas:")
    for venta in ventas:
        print(f"Modelo: {venta['modelo']} - Vendedor: {venta['vendedor']} - Cantidad: {venta['cantidad']}")

"""
Esta función crea un diccionario que contiene la cantidad total vendida por cada vendedor.
Luego, imprime una lista de todos los vendedores con la cantidad total de ventas realizadas.
"""
        
def reporte_ventas_por_vendedor():
    print("Reporte de ventas por vendedor:")
    # Creamos un diccionario para almacenar las ventas por vendedor
    ventas_por_vendedor = {}
    for vendedor in vendedores:
        ventas_por_vendedor[vendedor] = 0
        
    # Sumamos las ventas por vendedor
    for venta in ventas:
        vendedor = venta["vendedor"]
        cantidad = venta["cantidad"]
        ventas_por_vendedor[vendedor] += cantidad
        
    # Imprimimos el reporte
    for vendedor, cantidad in ventas_por_vendedor.items():
        print(f"{vendedor}: {cantidad}")

"""
Esta función crea un diccionario que contiene la cantidad total vendida de cada producto.
Luego, imprime una lista de todos los productos con la cantidad total de ventas realizadas.

"""

def reporte_ventas_por_producto():
    print("Reporte de ventas por producto:")
    # Creamos un diccionario para almacenar las ventas por producto
    ventas_por_producto = {}
    for producto in inventario:
        modelo = producto["modelo"]
        ventas_por_producto[modelo] = 0
        
    # Sumamos las ventas por producto
    for venta in ventas:
        modelo = venta["modelo"]
        cantidad = venta["cantidad"]
        ventas_por_producto[modelo] += cantidad
        
    # Imprimimos el reporte
    for modelo, cantidad in ventas_por_producto.items():
        print(f"Modelo: {modelo} - Cantidad vendida: {cantidad}")

"""
Esta función guarda el estado actual del inventario y las ventas en un archivo de texto llamado "inventario_ventas.txt".
Primero, se crea y se abre un archivo de texto en modo de escritura. 
Luego, se escribe en el archivo una lista de todos los productos en el inventario y una lista de todas las ventas realizadas.
Por último, se cierra el archivo y se imprime un mensaje indicando que el estado se guardó correctamente.

"""


def guardar_estado():
    with open("inventario_ventas.txt", "w") as f:
        # Guardar inventario
        f.write("Inventario:\n")
        for producto in inventario:
            f.write(f"{producto['modelo']},{producto['nombre']},{producto['cantidad']}\n")
        
        # Guardar ventas
        f.write("\nVentas:\n")
        for venta in ventas:
            f.write(f"{venta['modelo']},{venta['vendedor']},{venta['cantidad']}\n")
    
    print("Estado guardado correctamente en el archivo 'inventario_ventas.txt'.")



"""
El ciclo while en el código se utiliza para mostrar un menú de opciones al usuario y llamar a la función correspondiente
según la opción seleccionada por el usuario. Si el usuario selecciona la opción "0", el ciclo termina y el programa finaliza.
"""

while True:
    print("Bienvenido al sistema de inventario y ventas de GamePlanet.")
    print("Por favor, seleccione una opción del menú:")
    print("1. Registrar venta")
    print("2. Registrar llegada de artículos al almacén")
    print("3. Consultar datos del inventario")
    print("4. Consultar datos de las ventas")
    print("5. Mostrar reporte de ventas por vendedor")
    print("6. Mostrar reporte de ventas por producto")
    print("7.Guardar estado actual en archivo")
    print("0. Salir")
    opcion = input("Ingrese la opción deseada: ")
    if opcion == "1":
        registrar_venta()
    elif opcion == "2":
        registrar_llegada()
    elif opcion == "3":
        consultar_inventario()
    elif opcion == "4":
        consultar_ventas()
    elif opcion == "5":
        reporte_ventas_por_vendedor()
    elif opcion == "6":
        reporte_ventas_por_producto()
    elif opcion == "7":
        guardar_estado()
  
    
    elif opcion == "0":
        print("Gracias por usar nuestro sistema.")
        break
    else:
     print("Opción inválida. Por favor, seleccione una opción del menú.")

     
    

        


    
   
   
    
   


    

    

    

 






 