"""
	BSI08
	Mikołaj Jakubowski (s18860@pjwstk.edu.pl)

	Encryption library used in the project:
	https://pycryptodome.readthedocs.io/en/latest/src/installation.html
"""
from Crypto.Cipher import DES, Blowfish, AES
from Crypto.PublicKey import RSA
from Crypto.Util.Padding import pad, unpad
from Crypto.Cipher import PKCS1_OAEP
import sys
import base64

def option(cipher):
    """Menu continuation, makes life simpler

    Args:
        cipher (string): Desired algorithm type

    Returns:
        string: User's input
    """
    print(f' {cipher}')
    print('    1. Encode')
    print('    2. Decode')
    if (cipher == 'RSA'):
        print('    3. Generate keys')
    choice = input("\n Option: ")
    print('=========================================')
    return choice

def rsa():
    """RSA Algorithm, generates keys and allows to encrypt/decrypt a message
    """
    choice = option('RSA')
    if (choice == "1"):
        print('\nPublic key (after CTRL+V + ENTER, type (CTRL+Z + ENTER or CTRL+D + ENTER) to SAVE): ')
        s = sys.stdin.read().encode('utf8')
        publicKey = PKCS1_OAEP.new(RSA.importKey(s))

        print('\nMessage to be encrypted: ')
        msgCrypted = publicKey.encrypt(input().encode('utf8'))
        print(f'Encrypted message: {msgCrypted}')
    if (choice == "2"):
        print('\nPrivate key (after CTRL+V + ENTER, type (CTRL+Z + ENTER or CTRL+D + ENTER) to SAVE): ')
        s = sys.stdin.read().encode('utf8')
        privateKey = PKCS1_OAEP.new(RSA.importKey(s))

        print('\nMessage to be decrypted: ')
        msgDecrypted = privateKey.decrypt(input())
        print(f'Decrypted message: {msgDecrypted}')
    if (choice == "3"):
        key = RSA.generate(1024)
        privateKey = key.exportKey().decode('utf8')
        publicKey = key.publickey().exportKey().decode('utf8')
        print(f'\n{publicKey}\n\n{privateKey}')

def des():
    """DES Algorithm, encrypts/decrypts a message by providing passphrase
    """
    choice = option('DES')
    if (choice == "1"):
        plainText = input('Message to be encrypted: ').encode('utf8')
        des = DES.new(input('Password for the message (8, 16.. characters): ').encode('utf8'), DES.MODE_ECB)
        msgCrypted = base64.b64encode(des.encrypt(pad(plainText, 64))).decode('utf8')
        print(f'Encrypted message: {msgCrypted}')
    if (choice == "2"):
        msgCrypted = base64.b64decode(input('Message to be decrypted: '))
        des = DES.new(input('Password for the message: ').encode('utf8'), DES.MODE_ECB)
        msgDecrypted = unpad(des.decrypt(msgCrypted), 64).decode('utf8')
        print(f'Decrypted message: {msgDecrypted}')

def aes():
    """AES Algorithm, encrypts/decrypts a message by providing passphrase
    """
    choice = option('AES')
    if (choice == "1"):
        plainText = input('Message to be encrypted: ').encode('utf8')
        aes = AES.new(input('Password for the message (16, 32.. characters): ').encode('utf8'), AES.MODE_ECB)
        msgCrypted = base64.b64encode(aes.encrypt(pad(plainText, 128))).decode('utf8')
        print(f'Encrypted message: {msgCrypted}')
    if (choice == "2"):
        msgCrypted = base64.b64decode(input('Message to be decrypted: '))
        aes = AES.new(input('Password for the message: ').encode('utf8'), AES.MODE_ECB)
        msgDecrypted = unpad(aes.decrypt(msgCrypted), 128).decode('utf8')
        print(f'Decrypted message: {msgDecrypted}')

def blowfish():
    """Blowfish Algorithm, encrypts/decrypts a message by providing passphrase
    """
    choice = option('Blowfish')
    if (choice == "1"):
        plainText = input('Message to be encrypted: ').encode('utf8')
        blowfish = Blowfish.new(input('Password for the message (8, 16.. characters): ').encode('utf8'), Blowfish.MODE_ECB)
        msgCrypted = base64.b64encode(blowfish.encrypt(pad(plainText, 64))).decode('utf8')
        print(f'Encrypted message: {msgCrypted}')
    if (choice == "2"):
        msgCrypted = base64.b64decode(input('Message to be decrypted: '))
        blowfish = Blowfish.new(input('Password for the message: ').encode('utf8'), Blowfish.MODE_ECB)
        msgDecrypted = unpad(blowfish.decrypt(msgCrypted), 64).decode('utf8')
        print(f'Decrypted message: {msgDecrypted}')

def main():
    """DES Algorithm, encrypts/decrypts the message by providing passphrase
    """
    choice = True
    while choice:
        print('\n=========================================')
        print(' Asymmetric')
        print('    1. RSA')
        print('    2. ElGamal')
        print(' Symmetric')
        print('    3. DES')
        print('    4. AES')
        print('    5. Blowfish')
        choice = input('\n Option: ')
        print('=========================================')
        
        if choice == "1":
            rsa()
        elif choice == "2":
            break
            #todo
        elif choice == "3":
            des()
        elif choice == "4":
            aes()
        elif choice == "5":
            blowfish()
    main()

if __name__ == "__main__":
    main()