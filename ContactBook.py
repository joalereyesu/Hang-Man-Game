import os, sys, yaml, requests, json

contacts = {}

getFile = requests.get('http://demo7130536.mockable.io/contacts')
open('contacts.json', 'wb').write(getFile.content)
with open('contacts.json', 'r') as JSON:
    contacts = json.load(JSON)

print(contacts)

def NewContact():
    nombre = input("Ingrese nombre del nuevo contacto\n")
    while(not(all(c.isalpha() or c == ' ' for c in nombre))):
        nombre = input("es un nombre invalido\nPor favor ingrese el NOMBRE y APELLIDO del nuevo contacto:")
    else:
        print(f'nuevo contacto: {nombre}')

    phone = input("Ingrese telefono del nuevo contacto\n")
    email = input("Ingrese el correo del nuevo contacto\n")
    company = input("Ingrese la compañia o el lugar en donde trabaja del nuevo contacto\n")
    extra = input("Ingrese informacion extra del nuevo contacto\n")
    contacts[nombre] = {phone, email, company, extra}

def EditContact():
    nombre = input('ingrese nombre y apellido del contacto que desea editar\n')
    input_edition = int(input('1. Editar Telefono\n2. Editar Correo\n3. Editar Empresa\n4. Editar Extra\n 5. Regresar a Menu\n'))
    leave = False
    while not leave:
        if input_edition ==1:
            phone = input('ingrese nuevo telefono del contacto\n')
            continue
        if input_edition == 2:
            email = str(input("Ingrese nuevo correo del contacto\n"))
            continue                                                            #aqui hay que ver que pedo, por que no funcio
        if input_edition == 3:
            company = str(input("ingrese nueva empresa del contacto\n"))
            continue
        if input_edition == 4:
            extra = str(input("ingrese nueva informacion extra del contacto"))
        elif input_edition ==5:
            leave = True
    exists = nombre in contacts
    if exists:
        contacts[nombre] = phone
    else:
        print("El contacto no existe, intentelo de nuevo\n")

def SearchContact():
    nombre = input("Ingrese nombre del contacto que quiere buscar\n")
    exists = nombre in contacts

    if exists:
        print(nombre + " " + contacts[nombre])
    else:
        print("El contacto no existe, intentelo de nuevo\n")

def EliminateContact():
    nombre = input("Ingrese nombre del contacto que quiere eliminar\n")
    exists = nombre in contacts

    if exists:
        del contacts[nombre]
        print("Contacto eliminado con exito!\n")
    else:
        print("El contacto no existe, intentelo de nuevo\n")

def SeeContacts():
    for key,value in contacts.item():
        print(key + " " + value)

def csvContactos ():
    with open('Your_Contact_List.yaml', 'w') as f:
        new_doc = yaml.dump(contacts, f)
        print(yaml.dump(contacts))
        print('has copiado los datos al archivo llamado Your_Contact_List')

while not exit:

    input_menu = int(input(" 1. Crear Contacto \n 2. Editar Contacto\n 3. Buscar Contacto\n 4. Eliminar Contacto\n 5.Ver Contactos\n 6. Agregar Contactos a Archivo\n 7. Salir\n"))
    if input_menu == 1:
        NewContact()
    if input_menu == 2:
        EditContact()
    if input_menu == 3:
        SearchContact()
    if input_menu == 4:
        EliminateContact()
    if input_menu == 5:
        SeeContacts()
    if input_menu == 6:
        csvContactos ()
    elif input_menu == 7:
        exit = True