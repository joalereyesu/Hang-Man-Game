import os, sys, yaml, requests, json

contacts = {}

getFile = requests.get('http://demo7130536.mockable.io/contacts')
open('contacts.json', 'wb').write(getFile.content)
with open('contacts.json', 'r') as JSON:
    contacts = json.load(JSON)

def NewContact():
    nombre = input("Ingrese nombre del nuevo contacto\n")
    phone = input("Ingrese telefono del nuevo contacto\n")
    email = input("Ingrese el correo del nuevo contacto\n")
    company = input("Ingrese la compañia o el lugar en donde trabaja del nuevo contacto\n")
    extra = input("Ingrese informacion extra del nuevo contacto\n")
    letter = nombre[0]


    for key in contacts.items():
        if key == letter:
            dicletters = contacts[letter]
            print(dicletters)
            for key in dicletters.items():
                if key != nombre:
                    dicnames = contacts[letter][nombre]
                    print(dicnames)
                    for key in dicnames:
                        contacts[letter][nombre] = { }
                else:
                    print(f"El contacto {nombre} ya existe!")
                    dicnames = contacts[letter][nombre]
                    contacts[letter] = {nombre}
                    letter[nombre] = 'telefono'
                    letter[nombre]['telefono'] = phone
                    letter[nombre] = 'email'
                    letter[nombre]['email'] = email
                    letter[nombre] = 'company'
                    letter[nombre]['company'] = company
                    letter[nombre] = 'extra'
                    letter[nombre]['extra'] = extra




while (1):

    input_menu = int(input("1.Crear Contacto \n2.Editar Contacto\n3.Buscar Contacto\n4.Eliminar Contacto\n5.Ver Contactos\n6.Guardar contacto en Archivo\n7.Salir\n"))
    if input_menu == 1:
       NewContact()