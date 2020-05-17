import os, sys, yaml, requests, json, validators

exit = False

contacts = {}

getFile = requests.get('http://demo7130536.mockable.io/contacts')
open('contacts.json', 'wb').write(getFile.content)
with open('contacts.json', 'r') as JSON:
    contacts = json.load(JSON)

print(contacts)

def NewContact():
    nombre = input("Ingrese nombre del nuevo contacto\n")
    while(not(all(c.isalpha() or c == ' ' for c in nombre))):
        nombre = input("Es un nombre invalido\nPor favor ingrese el NOMBRE y APELLIDO del nuevo contacto:")
    else:
        print(f'nuevo contacto: {nombre}')
    
    while(1):
        phone = input("Ingrese telefono del nuevo contacto\n")
        for chars in phone:
            if chars.isnumeric():
                break
            else:
                print(f"El numero {phone} contiene una letra. Ingreselo de nuevo.")
        break
    
    while(1):
        email = input("Ingrese el correo del nuevo contacto\n")
        validate_email = validators.email(email)
        if validate_email == True:
            print(f"Email {email} es correcto\n")
            break
        else:
            print(f"Te equivocaste '{email}' no es un correo electronico valido,\n Debes ingresar algo como: ejemplo@example.com")
    
    company = input("Ingrese la compañia o el lugar en donde trabaja del nuevo contacto\n")
    extra = input("Ingrese informacion extra del nuevo contacto\n")
    letra = nombre[0]
    contacts[letra][nombre] = {'telefono': ' ', 'email': ' ', 'company': ' ', 'extra': ' '}
    contacts[letra][nombre]['telefono'] = phone
    contacts[letra][nombre]['email'] = email
    contacts[letra][nombre]['company'] = company
    contacts[letra][nombre]['extra'] = extra


def SearchContact():
    nombre = input("Ingrese nombre del contacto que quiere buscar\n")
    letra = nombre[0]
    existe = nombre in contacts[letra]

    if existe:
        print(nombre + " " + contacts[letra][nombre])
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
    contador = 0
    for letter, name in contacts.items():
        print(letter)
        for key in name:
            contador = contador + 1
            print(f"  {contador}. {key}")

    choice = int(input("Ver Contacto: "))
    if (choice == contador):
        print("Hola")
        print(f"{key}: {name[key]}")

            #if choice == contador:
                #print(key + ':', name[key])
                
    


def csvContactos ():
    with open('Your_Contact_List.yaml', 'w') as f:
        new_doc = yaml.dump(contacts, f)
        print(yaml.dump(contacts))
        print('has copiado los datos al archivo llamado Your_Contact_List')

while not exit:

    input_menu = int(input(" 1. Crear Contacto \n 2. Editar Contacto\n 3. Buscar Contacto\n 4. Eliminar Contacto\n 5.Ver Contactos\n 6. Agregar Contactos a Archivo\n 7. Salir\n"))
    if input_menu == 1:
        NewContact()
    #if input_menu == 2:
       # EditContact()
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