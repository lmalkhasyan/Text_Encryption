# Text Encription

### Task Brief:
### Write Simple Text Encriptor:

Encryption: 
 1.Letterlist pasted on a cube
 2.key generated
 2.Random Rotations based on key
 3.Substitution based on original orientation of the cube
 4.Cipher text generated

Decryption: 
1.Letterlist pasted on a cube
2.Rotations based on key
3.Substitution based on orientation of cube 
4.Plain text recovered, Letter list reinitialized with new state

Text_Encryptor interface:
1. encrypt(std::string &text) : key
2. decrypt(std::string &text, std::string key) : void
