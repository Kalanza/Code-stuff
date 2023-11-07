/*

Caesar Redux
Time limit: 1000 ms
Memory limit: 256 MB

The Caesar cipher is a simple encryption technique that was used by Julius Caesar to send secret messages to his allies. It works by shifting the letters in the plaintext message by a certain number of positions. Decryption is performed by shifting in the opposite direction by the same number of positions.

A program that implements this technique is needed to encrypt a plaintext message or decrypt a ciphertext messages. Spaces are not affected by encryption or decryption.

You need to determine whether the value that is provided is plaintext or ciphertext. If the value provided is plaintext, you should output the encrypted message given the shift value above. If the provided value is ciphertext, you should output the decrypted message.

Standard Input
Input begins with an integer 
�
n on a line by itself that indicates how many messages are in the input.

The next 
2
�
2n lines contain a line with the shift amount followed by a line with either a plaintext or a ciphertext message.

Standard Output
For each message in the input, output the plaintext if the message is ciphertext, or the ciphertext if the message is plaintext.

Constraints and notes
1
≤
�
≤
25
1≤n≤25
The shift value will be between 1 and 25, inclusive.
Each message will consist of lowercase letters and spaces, and contain between 3 and 300 characters.
If the message provided contains the word "the", then it is plaintext. Otherwise, it is ciphertext.
Input	Output
2
19
we accept the ieeextreme challenge
19
qbspbz jhlzhy olsk aol vmmpjl vm wvuapmle theptbz wypvy av iljvtpun kpjahavy
dl hjjlwa aol pllleayltl johsslunl
julius caesar held the office of pontifex maximus prior to becoming dictator

C++
                print(encrypted)
*/
def caesar_cipher(text, shift):
    encrypted_text = ""
    for char in text:
        if char == " ":
            encrypted_text += " "
        elif char.isalpha():
            shifted = ord(char) + shift
            if char.islower():
                if shifted > ord("z"):
                    shifted -= 26
            encrypted_text += chr(shifted)
        else:
            encrypted_text += char
    return encrypted_text

def caesar_decrypt(text, shift):
    decrypted_text = ""
    for char in text:
        if char == " ":
            decrypted_text += " "
        elif char.isalpha():
            shifted = ord(char) - shift
            if char.islower():
                if shifted < ord("a"):
                    shifted += 26
            decrypted_text += chr(shifted)
        else:
            decrypted_text += char
    return decrypted_text

n = int(input())
for _ in range(n):
    shift = int(input())
    message = input(). strip()
    if shift >= 1 and shift <= 25:
        if n >=1 and n <=25 and len(message) >=3 and len(message) <=300:
            messages = message.split(' ')
            if "the" in messages:
                # If the message contains "the", it's plaintext. So, decrypt it.
                decrypted = caesar_decrypt(message, shift)
                print(decrypted)
            else:
                # If not, it's ciphertext. Encrypt it.
                encrypted = caesar_cipher(message, shift)
                print(encrypted)

  
  
