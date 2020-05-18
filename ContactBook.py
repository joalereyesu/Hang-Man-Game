import os, sys, yaml, requests, json, validators, emoji, time

exit = False

contacts = {}

getFile = requests.get('http://demo7130536.mockable.io/final-contacts-100')
open('contacts.json', 'wb').write(getFile.content)
with open('contacts.json', 'r') as JSON:
    contacts = json.load(JSON)

def contactsByNumber():
    contador = 0
    choice = int(input("Ver Contacto: "))
    for letter, name in contacts.items():
        newdic = contacts[letter]
        for name in newdic.items():
            contador = contador + 1
            key = newdic.keys()
            for key in name:
                if choice == contador:
                    contact = key
                    print(contact)
    return contact

def NewContact():
    nombre = input("\nIngrese nombre del nuevo contacto\n")
    for c in nombre:
        if c.isalpha():
                break
        else:
            print("Ingresa unicamente letras para el nombre y el apellido")

    while(1):
        phone = input("\nIngrese telefono del nuevo contacto\n")
        for chars in phone:
            if chars.isnumeric():
                break
            else:
                print(f"El numero {phone} contiene una letra. Ingreselo de nuevo.")
        break
    
    while(1):
        email = input("\nIngrese el correo del nuevo contacto\n")
        validate_email = validators.email(email)
        if validate_email == True:
            print(f"Email {email} es correcto\n")
            break
        else:
            print(f"Te equivocaste '{email}' no es un correo electronico valido,\n Debes ingresar algo como: ejemplo@example.com")
    
    company = input("\nIngrese la compañia o el lugar en donde trabaja del nuevo contacto\n")
    extra = input("\nIngrese informacion extra del nuevo contacto\n")
    letra = nombre[0]
    print(letra)
    exist = letra in contacts
    if exist:
        contacts[letra][nombre] = {'telefono': ' ', 'email': ' ', 'company': ' ', 'extra': ' '}
        contacts[letra][nombre]['telefono'] = phone
        contacts[letra][nombre]['email'] = email
        contacts[letra][nombre]['company'] = company
        contacts[letra][nombre]['extra'] = extra
        print(contacts)
    else:
        newletter = {nombre : {'telefono': ' ', 'email': ' ', 'company': ' ', 'extra': ' ' }}
        contacts[letra] = newletter
        contacts[letra][nombre]['telefono'] = phone
        contacts[letra][nombre]['email'] = email
        contacts[letra][nombre]['company'] = company
        contacts[letra][nombre]['extra'] = extra
        print(contacts)


def SearchContact():
    output = []
    userChoice = input("\ningrese a quien desea buscar: ")
    for i in contacts.keys():
        for name in contacts[i].keys():
            found = False
            nameList = name.split()
            for sub in nameList:
                if sub[:len(userChoice)].lower() == userChoice.lower():
                    found = True
                    break
            if found == True:
                output.append(name)
    print(output)

def EliminateContact():
    print("MENU:\n1.Buscar Contactos por medio de nombre\n2.Buscar contactos por medio de su numero asigando")
    choice = int(input("Ingrese su opcion: "))

    if choice == 1:
        input_nombre = input("\nIngrese nombre del contacto que quiere eliminar\n")
        letra = input_nombre[0]
        existe = input_nombre in contacts[letra]
        if existe:
            start = 0
            del contacts[letra][input_nombre]
            print("Contacto eliminado con exito!\n" + emoji.emojize(':name_badge:'))
            while start < 3:
                m, s = divmod(start, 60)
                h, m = divmod(m, 60)
                str(h).zfill(2) + ":"  + str(s).zfill(2)
                time.sleep(1)
                start += 1
                if (start == 3):
                    os.system('clear')
                    break
        else:
            input("El contacto no existe, intentelo de nuevo\n")
    if choice ==2:
        choice = int(input("\nIngrese numero del contacto que quiere eliminar\n"))
        contador = 0
        for letter, name in contacts.items():
            newdic = contacts[letter]
            for name in newdic.items():
                contador = contador + 1
                key = newdic.keys()
                for key in name:
                    if choice == contador:
                        contact = key
                        print(contact)
                        del contact
                        #print(contact)
                            #print("Contacto eliminado con exito!\n")
                            #break
                        #else: 
                            #print("El contacto no existe, intentelo de nuevo\n")


def SeeContacts():
    contador = 0
    for letter, name in contacts.items():
        print(letter)
        for key in name:
            contador = contador + 1
            print(f"  {contador}. {key}")
                
    


def csvContactos ():
    with open('Your_Contact_List.yaml', 'w') as f:
        yaml.dump(contacts, f)
        print(yaml.dump(contacts))
        print('has copiado los datos al archivo llamado Your_Contact_List')

def CallContact ():
    start = 0
    print("MENU:\n1.Llamar contactos por medio de nombre\n2.Llamar contactos por medio de su numero asigando")
    choice = int(input("Ingrese su opcion: "))
    if choice == 1:
        llamando = input("Ingrese el nombre del contacto que desea llamar:")
        letra = llamando[0]
        exists = llamando in contacts[letra]
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
    if choice == 2:
        llamando = int(input("Ingrese el nombre del contacto que desea llamar:"))
        contador = 0
        for letter, name in contacts.items():
            newdic = contacts[letter]
            for name in newdic.items():
                contador = contador + 1
                key = newdic.keys()
                for key in name:
                    if llamando == contador:
                        print(emoji.emojize(':telephone_receiver:') + f' estas llamando a "{key}"...')
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
    print("MENU:\n1.Mandar mensaje a contacto por medio de nombre\n2.Mandar mensaje a contacto por medio de su numero asigando")
    choice = int(input("Ingrese su opcion: "))
    if choice == 1:
        sendmensaje = input("Ingrese el nombre del contacto al que desea mandar un mensaje:")
        letra = sendmensaje[0]
        exists = sendmensaje in contacts[letra]
        while not exists:
            input("El contacto no existe, intentelo de nuevo\n")
        else:
            mensaje = input("Mensaje:")
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
    if choice == 2:
        sendmensaje = int(input("Ingrese el numero del contacto al que desea mandar un mensaje:"))
        mensaje = input("Mensaje:")
        contador = 0
        for letter, name in contacts.items():
            newdic = contacts[letter]
            for name in newdic.items():
                contador = contador + 1
                key = newdic.keys()
                for key in name:
                    if sendmensaje == contador:
                        print(emoji.emojize(':outbox_tray:') + f'to: {key}\n>> {mensaje}\n')
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
    print("MENU:\n1.Mandar mensaje a contacto por medio de nombre\n2.Mandar mensaje a contacto por medio de su numero asigando")
    choice = int(input("Ingrese su opcion: "))
    if choice == 1:
        sendemail = input("Ingrese el nombre del contacto al que desea mandar un correo:")
        letra = sendemail[0]
        exists = sendemail in contacts[letra]
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
    if choice == 2:
        sendemail = int(input("Ingrese el numero del contacto al que desea mandar un correo:"))
        contador = 0
        for letter, name in contacts.items():
            newdic = contacts[letter]
            for name in newdic.items():
                contador = contador + 1
                key = newdic.keys()
                for key in name:
                    if sendemail == contador:
                        subject = input("subject:")
                        mensaje2 = input("mensaje:")
                        print(emoji.emojize(':e-mail:') + f'\nsending email to: {key}\n- {subject}\n>>{mensaje2}\n')
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

    input_menu = int(input("\n 1. Crear Contacto \n 2. Buscar Contacto\n 3. Ver Contactos\n 4. Eliminar Contacto\n 5. Llamar Contacto\n 6. Enviar Mensaje a Contacto\n 7. Enviar Correo a Contacto\n 8. Agregar Contactos a Archivo\n 9. Salir\n"))
    if input_menu == 1:
        NewContact()
    if input_menu == 2:
        SearchContact()
    if input_menu == 3:
        SeeContacts()
        contactsByNumber()
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
