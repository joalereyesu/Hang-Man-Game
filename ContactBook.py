import os, sys, yaml, requests, json, validators, emoji, time

exit = False

contacts = {}

getFile = requests.get('http://demo7130536.mockable.io/contacts')
open('contacts.json', 'wb').write(getFile.content)
with open('contacts.json', 'r') as JSON:
    contacts = json.load(JSON)

def NewContact():
    nombre = input("Ingrese nombre del nuevo contacto\n")
    for c in nombre:
        if c.isalpha():
                break
        else:
            print("Ingresa unicamente letras para el nombre y el apellido")

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

    while not existe:
        input("El contacto no existe, intentelo de nuevo\n")
    else:
        print(nombre + " " + contacts[nombre])

def EliminateContact():
    input_nombre = input("Ingrese nombre del contacto que quiere eliminar\n")
    existe = input_nombre in contacts

    if existe:
        del contacts[input_nombre]
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
        yaml.dump(contacts, f)
        print(yaml.dump(contacts))
        print('has copiado los datos al archivo llamado Your_Contact_List')

def CallContact ():
    start = 0
    llamando = input("ingrese el nombre del contacto que desea llamar:")
    exists = llamando in contacts
    while not exists:
        input("El contacto no existe, intentelo de nuevo\n")
    else:
        print(emoji.emojize(':telephone_receiver:') + f' estas llamando a "{llamando}"...')
    while start < 3:
         m, s = divmod(start, 60)
         h, m = divmod(m, 60)
         str(h).zfill(2) + ":"  + str(s).zfill(2)
         time.sleep(1)
         start += 1
         if (start == 3):
             os.system('clear')
             break

def MessageContact():
    start = 0
    sendmensaje = input("ingrese el nombre del contacto al que desea mandar un mensaje:")
    exists = sendmensaje in contacts
    while not exists:
        input("El contacto no existe, intentelo de nuevo\n")
    else:
        mensaje = input("mensaje:")
        print(emoji.emojize(':outbox_tray:') + f'to: {sendmensaje}\n>> {mensaje}\n')
    while start < 5:
         m, s = divmod(start, 60)
         h, m = divmod(m, 60)
         str(h).zfill(2) + ":"  + str(s).zfill(2)
         time.sleep(1)
         start += 1
         if (start == 3):
             os.system('clear')
             break

def EmailContact():
    start = 0
    sendemail = input("ingrese el nombre del contacto al que desea mandar un correo:")
    exists = sendemail in contacts
    while not exists:
        input("El contacto no existe, intentelo de nuevo\n")
    else:
        subject = input("subject:")
        mensaje2 = input("mensaje:")
    print(emoji.emojize(':e-mail:') + f'\nsending email to: {sendemail}\n- {subject}\n>>{mensaje2}\n')
    while start < 6:
         m, s = divmod(start, 60)
         h, m = divmod(m, 60)
         str(h).zfill(2) + ":"  + str(s).zfill(2)
         time.sleep(1)
         start += 1
         if (start == 3):
             os.system('clear')
             break

while not exit:

    input_menu = int(input(" 1. Crear Contacto \n 2. Buscar Contacto\n 3. Ver Contactos\n 4. Eliminar Contacto\n 5. Llamar Contacto\n 6. Enviar Mensaje a Contacto\n 7. Enviar Correo a Contacto\n 8. Agregar Contactos a Archivo\n 9. Salir\n"))
    if input_menu == 1:
        NewContact()
    if input_menu == 2:
        SearchContact()
    if input_menu == 3:
        SeeContacts()
    if input_menu == 4:
        EliminateContact()
    if input_menu == 5:
        CallContact()
    if input_menu == 6:
        MessageContact()
    if input_menu == 7:
        EmailContact()
    if input_menu == 8:
        csvContactos ()
    if input_menu == 9:
        exit = True