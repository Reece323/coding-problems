// 
// streamValidation
// 
// A character in UTF-8 can be anywhere from 1 to 4 bytes long. The bytes are 8 bits long and are subject to the following rules:
// 
// For a 1-byte character, the first bit is a 0, followed by its unicode code.
// For an n-byte character, the first n bits are all 1s and the n + 1 bit is 0. This is followed by n - 1 bytes in which the 2 most significant bits (that is, the leftmost 2) are 10.
// This is how the UTF-8 encoding would work:
// 
//    Char. number range  |        UTF-8 octet sequence
//       (hexadecimal)    |              (binary)
//    --------------------+---------------------------------------------
//    0000 0000-0000 007F | 0xxxxxxx
//    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// Given an array of integers representing the data, return true if it can be converted to a valid UTF-8 encoding, otherwise return false.
// 
// Example
// 
// For stream = [197, 130, 1], the output should be
// streamValidation(stream) = true.
// 
// The input stream, when converted from decimal to binary numbers, represents the following octet sequence: 11000101 10000010 00000001. The first 2 bits are 1s and the 3rd bit is 0, meaning that this sequence is a valid UTF-8 encoding of a 2-byte character followed by a 1-byte character, making the answer true.
// 
// For stream = [235, 140, 4], the output should be
// streamValidation(stream) = false.
// 
// The input stream, when converted from decimal to binary numbers, represents the following octet sequence: 11101011 10001100 00000100. The first 3 bits are all 1s and the 4th bit is 0, meaning that this is a 3-byte character. The next byte is a correct continuation byte since it starts with 10. However, the second continuation byte is invalid because it does not start with 10, making the answer false.
// 
// Definition for arrays:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//

bool streamValidation(arr_integer stream) {
    int flag = 0x1 << 7;
    int nbytes = 0;
    
    if (stream.size == 0)
        return false;
    
    for (int i = 0; i < stream.size; i++) {
        if (nbytes == 0) {
            // validate header
            for (int j = 0; j <= 4; j++) {
                if (!(stream.arr[i] & (flag >> j)))
                    break;
                nbytes = j + 1;
            }
            if (nbytes == 1 || nbytes == 5)
                return false;
            // this header byte counts as 1
            if (nbytes >= 2)
                nbytes--;
        } else if (nbytes > 0) {
            // validate subsequent bytes
            if ((stream.arr[i] >> 6) != 0x2)
                return false;
            nbytes--;
        }
    }
    
    return (nbytes == 0);
}

