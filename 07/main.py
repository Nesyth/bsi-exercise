"""
	BSI07
	Mikołaj Jakubowski (s18860@pjwstk.edu.pl)

	Encryption library used in the project:
	https://pycryptodome.readthedocs.io/en/latest/src/installation.html
"""
import time
import multiprocessing as mp
from multiprocessing import Pool
from Crypto.Util.Padding import unpad
from Crypto.Cipher import DES
from itertools import chain, product

######### CONFIG #########
dictionary = 'abcdefghijklmnopqrstuvwxyz'
minLength = 4
maxLength = 12
encryptedText = b"M\xe9\x07M\x0c\x1f3\xa0\x88L\x08\xde\x9c[\xac\x97;\xe3\xac\x02z\xde\xc7'\xcdx+\xfc\x9b\x0fcr \xed\x0fX\xab\xe7\xed\xba}\xefP\x90-\x92\xb9\xe4+\xc5\xc0\xc4\xc1\x01\xd1oZ\x1eD*\xc6\xf6Ze\xe1\xc8i\xec\x94\xa9\xf0~\xa3\xf1\r]6M\x97\xc8\x80\xce\x1a\x0f\xc9Ky\xd0\x07c=YL\xc1\xff\xb99b\x08\xda\xce\x93\x05\xfc\xe3\x8c\x11\xf7w\xce\xec$\xceu\xb8\xbf\xd5xI\x97\xe1\xe4\xfaK\x11\xb2z\xaaP,Q\xe7\xb7<\xef7\xff\x862\xd0dz^\xb5\r\x89\x8a\xd2d\x8d\xc8\xe7q\xe7\x1e89\x9aN9\x11\xdaHX\xb6\xb0\xe2\x8b^Z\xd3\x87P\xe7;\x87\xd1z^\xa3!\x12g*f\xb1Fe\xdd\x1a\xeb\xde\xc3\x8d\xfd\x99\x7f\xb7\xc4\xdd\x94\xf6\xdd\xd71\x9b\x0e\x04:\x18-\xee}\x0f\xa8#\x15ff\x9a\x9d\xfb\x8fl"
BLOCK_SIZE = 32
##########################

dictionaryPool = []

def bruteDictionary(dictPool, charset, min, max):
	"""Creates the wordset for bruteforce to work on

	Args:
		dictPool (string): A string of selected characters from the charset
		charset (string): A whole charset
		min (integer): Min length of generated words
		max (integer): Max length of generated words
	"""
	for i in range(0, len(dictPool)):
		return (dictPool[i] + ''.join(candidate)
			for candidate in chain.from_iterable(product(charset, repeat = i)
				for i in range(min - 1, max + 1)))

def bruteforce(dictPool):
	"""Creates the key based on newly generated word, then tries to uncrypt the whole given text

	Args:
		dictPool (string): A string of selected characters from the charset
	"""
	start = time.time()
	notFound = True
	while notFound:
		for attempt in bruteDictionary(dictPool, dictionary, minLength, maxLength):
			try:
				des = DES.new(bytes(attempt, encoding = 'UTF-8'), DES.MODE_ECB)
				decryptedText = str(unpad(des.decrypt(encryptedText), BLOCK_SIZE), 'UTF-8')
				if decryptedText:
					start -= time.time()
					print(f'\nDECRYPTED TEXT: {decryptedText}')
					print(f'PASSWORD: {attempt}')
					print('TIME ELAPSED: {:0.2f}s'.format(-start))
					notFound = False
					break
			except:
				# print(f'Key: {attempt}')
				pass

def brutePool():
	"""Makes array of strings based on given charset and available cores

	Returns:
		dictionaryPool (array): Array of strings for asynchronous computing
	"""
	letters = 0
	cpu_count = mp.cpu_count()

	for k in range(0, cpu_count):
		dictionaryPool.append('')

	while (letters != len(dictionary)):
		for v in range(0, cpu_count):
			if (letters < len(dictionary)):
				dictionaryPool[v] += dictionary[letters]
				letters += 1

	return dictionaryPool

def main():
	"""Main, generates workers underneath the intro
	"""
	print('================== DES BRUTEFORCE PASSWORD CRACKING ==================')
	print(f'Encrypted text: {encryptedText}')
	print(f'Min password length: {minLength}')
	print(f'Max password length: {maxLength}')
	print(f'Dictionary: {dictionary}')
	print(f'Cores on machine to be used: {mp.cpu_count()}')
	print('======================================================================')
	print('\nWorking...\n')

	core = 0
	p = Pool(mp.cpu_count())
	for i in brutePool():
		core += 1
		print(f'Core {core}: {i}')
		p.apply_async(bruteforce, args=(i, ), callback=quit)
	p.close()
	p.join()

if __name__ == "__main__":
    main()