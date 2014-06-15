/* Machine Endian check
 * ====================
 * This functions can check the machine is Little Endian or Big Endian
 * 
 * return 1/Little Endian; 0/Big Endian
 */


uint8_t
isMachineLittleEndian(void) {
				static int endian_check_int = 1;

				/* 0=big endian|xdr -- 1=little endian|ndr */
				return *((uint8_t *) & endian_check_int);
}
