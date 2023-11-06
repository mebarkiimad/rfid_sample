#ifndef __APPTOOLS_H__
#define __APPTOOLS_H__

// ******************************************************************
// ****** Timer Functions *******************************************
// ******************************************************************

void StartTimer(unsigned long Duration);
void StopTimer(void);
bool TestTimer(void);

// ******************************************************************
// ****** General Communication *************************************
// ******************************************************************

bool TestByte(int Channel);
// byte ReadByte(int Channel); -> is System Function
bool TestChar(int Channel);
char ReadChar(int Channel);

// void WriteByte(int Channel,byte Byte); -> is System Function
void WriteChar(int Channel,char Char);
void WriteString(int Channel,const char *String);
void WriteRadix(int Channel,const byte *ID,int BitCnt,int DigitCnt,int Radix);
void WriteBin(int Channel,const byte *ID,int BitCnt,int DigitCnt);
void WriteDec(int Channel,const byte *ID,int BitCnt,int DigitCnt);
void WriteHex(int Channel,const byte *ID,int BitCnt,int DigitCnt);
void WriteVersion(int Channel);

// ******************************************************************
// ****** Host Communication ****************************************
// ******************************************************************

//void SetHostChannel(int Channel);

bool HostTestByte(void);
byte HostReadByte(void);
bool HostTestChar(void);
char HostReadChar(void);

void HostWriteByte(byte Byte);
void HostWriteChar(char Char);
void HostWriteString(const char *String);
void HostWriteRadix(const byte *ID,int BitCnt,int DigitCnt,int Radix);
void HostWriteBin(const byte *ID,int BitCnt,int DigitCnt);
void HostWriteDec(const byte *ID,int BitCnt,int DigitCnt);
void HostWriteHex(const byte *ID,int BitCnt,int DigitCnt);
void HostWriteVersion(void);

int sprintf(char *Buffer,const char *Format,...);
int cprintf(int Channel,const char *Format,...);
int hprintf(const char *Format,...);

// ******************************************************************
// ****** Beep Functions ********************************************
// ******************************************************************

void SetVolume(int NewVolume);
int GetVolume(void);
void BeepLow(void);
void BeepHigh(void);

// ******************************************************************
// ****** Compatibility to TWN3 *************************************
// ******************************************************************

int ConvertTagTypeToTWN3(int TagTypeTWN4);

// ******************************************************************
// ****** LEGIC Mini-API ********************************************
// ******************************************************************

bool LEGIC_Select(int TagType);
bool LEGIC_SearchSegmentByStamp(const byte* Stamp,int StampLength);
bool LEGIC_ReadSegment(int Offset,int ByteCnt,byte *Data);

// ******************************************************************
// ****** NFC *******************************************************
// ******************************************************************

typedef struct
{
	byte* Header;
	byte TypeLength;
	int PayloadLength;
	byte IDLength;
	byte* Type;
	byte* ID;
	byte* Payload;
	byte* NextRecord;
} TNDEFRecord;

#define NDEF_IsMBSet(Header)	(Header & 0x80)
#define NDEF_IsMESet(Header)	(Header & 0x40)
#define NDEF_IsCFSet(Header)	(Header & 0x20)
#define NDEF_IsSRSet(Header)	(Header & 0x10)
#define NDEF_IsILSet(Header)	(Header & 0x08)
#define NDEF_GetTNF(Header)		(Header & 0x07)

bool NDEF_WaitConnect(void);
bool NDEF_ReceiveRecord(byte *RecordType,int *RecordTypeLength,int MaxRecordTypeLength,
                        byte *RecordData,int *RecordDataLength,int MaxRecordDataLength);

// ******************************************************************
// ****** BLE *******************************************************
// ******************************************************************

#define LEN_MOBILE_ID		16

const char *BLEGetEventString(int Event);
void BLECalcWalletKey(const byte *Source,byte *Dest);

#endif
