#ifndef SPLASH_H
#define SPLASH_H

#include "src/protocol.h"

padByte splash[]={
0x1b,
0x02,
0x1b,
0x0c,
0x1b,
0x12,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1d,
0xaf,
0xf0,
0xc0,
0x1b,
0x5a,
0x1b,
0xd1,
0xc0,
0x44,
0x41,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0x5a,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0x2e,
0xf0,
0x21,
0xc0,
0x1b,
0x5a,
0x1b,
0x12,
0x1d,
0x2d,
0xee,
0xa0,
0xc9,
0xaf,
0x71,
0xc9,
0xf5,
0xca,
0x77,
0xcc,
0xf9,
0x4e,
0xfa,
0xcf,
0x7b,
0xd4,
0x7b,
0x21,
0x44,
0xfa,
0xc9,
0x78,
0xcc,
0xf6,
0x50,
0x74,
0xd1,
0x71,
0x53,
0xee,
0x55,
0x6c,
0x56,
0x66,
0xd7,
0xe1,
0xd7,
0x2e,
0xfc,
0x56,
0xf9,
0xd4,
0xf6,
0xd2,
0x74,
0x50,
0x72,
0x4d,
0xf0,
0xc9,
0xee,
0xc3,
0xed,
0xa0,
0x5a,
0x59,
0x2d,
0xee,
0x59,
0xc9,
0x1d,
0x2e,
0xfc,
0x59,
0xaf,
0x6c,
0x59,
0x6c,
0x21,
0xc0,
0x42,
0xeb,
0xc3,
0x6a,
0x44,
0x69,
0xc5,
0xe7,
0xc6,
0x65,
0x47,
0xe1,
0xc6,
0x2e,
0x7e,
0x44,
0xfc,
0x41,
0xc0,
0xfc,
0xa0,
0x59,
0x1d,
0x2d,
0xf6,
0x21,
0xdb,
0xaf,
0xfa,
0xdb,
0xfa,
0x22,
0x4b,
0x2d,
0xfc,
0x4b,
0xfc,
0xa3,
0x42,
0xee,
0x42,
0xee,
0x22,
0x44,
0x42,
0xf0,
0x21,
0x5f,
0x72,
0x5c,
0xf6,
0xdb,
0x1d,
0xee,
0xa3,
0x41,
0xaf,
0xf5,
0xd7,
0x77,
0xd8,
0x78,
0x59,
0xfa,
0x5a,
0x7b,
0xdb,
0xfc,
0xde,
0x7d,
0x24,
0xc0,
0x42,
0xfc,
0xc5,
0xfa,
0x48,
0x78,
0xc9,
0xf6,
0x4b,
0x2d,
0xee,
0xa5,
0x41,
0xee,
0x24,
0x50,
0x7d,
0xcc,
0x7d,
0xa3,
0xd7,
0xee,
0xd1,
0x41,
0x1d,
0x2e,
0x6c,
0x5a,
0xaf,
0xed,
0x24,
0x41,
0x2e,
0x6c,
0x48,
0x6c,
0xa3,
0x5a,
0x1d,
0x2d,
0xee,
0xa5,
0xc9,
0xaf,
0xed,
0xc9,
0xed,
0x24,
0x5a,
0x7b,
0x5a,
0x7b,
0xa6,
0x47,
0xed,
0x47,
0xed,
0xa5,
0x59,
0x2d,
0xee,
0x59,
0xc9,
0x1d,
0x2e,
0xf0,
0x27,
0xc6,
0x1d,
0x2d,
0xee,
0xc9,
0x6f,
0xc0,
0xf0,
0xa6,
0x5c,
0x71,
0xd8,
0xf5,
0x53,
0x78,
0xd1,
0xfc,
0x4d,
0x2e,
0x60,
0xca,
0x63,
0xca,
0x66,
0x48,
0x6c,
0xc6,
0x74,
0x44,
0xf5,
0x44,
0xf9,
0x44,
0x7d,
0xc5,
0xaf,
0xe1,
0xc6,
0x65,
0x48,
0xe8,
0xca,
0x6c,
0xcc,
0xee,
0x4e,
0xf0,
0x50,
0xf3,
0x53,
0xf5,
0x55,
0x77,
0xd8,
0x78,
0xdb,
0xfa,
0x5f,
0xfc,
0x27,
0xc5,
0x7d,
0x4d,
0x4e,
0xfc,
0xd4,
0x7b,
0x59,
0xf9,
0xde,
0x77,
0x28,
0x41,
0xf6,
0xc3,
0x74,
0xc6,
0x71,
0x48,
0xee,
0x4b,
0x6a,
0x4e,
0x65,
0x50,
0xe1,
0xd2,
0x2e,
0xfc,
0xd4,
0xfa,
0xd4,
0xf5,
0xd4,
0x72,
0xd4,
0x6c,
0x53,
0x69,
0xd2,
0xe4,
0x50,
0xe1,
0xcf,
0x2d,
0x7d,
0xcc,
0xfa,
0xc9,
0xf6,
0xc6,
0xf3,
0xc3,
0x71,
0x27,
0xde,
0x6f,
0xdb,
0xee,
0x56,
0xc9,
0x1d,
0xaf,
0x6c,
0xc9,
0x4d,
0xeb,
0xd2,
0x6a,
0x55,
0xe7,
0x5a,
0x65,
0xdd,
0xe1,
0x5f,
0x2e,
0x7d,
0x28,
0x41,
0xfa,
0x42,
0xf6,
0xc3,
0xf3,
0xc3,
0xed,
0x42,
0x6a,
0xc0,
0xe7,
0x27,
0xde,
0xe4,
0xdd,
0x63,
0x5a,
0xe1,
0xd8,
0x2d,
0xff,
0xff,
0xd4,
0x7e,
0x50,
0x7d,
0x4d,
0xca,
0x7e,
0xc5,
0x2e,
0x60,
0x42,
0xe2,
0xa6,
0x5f,
0x63,
0x5c,
0x66,
0x5a,
0x69,
0xd8,
0xeb,
0xd7,
0x6c,
0x56,
0xf0,
0x55,
0x74,
0x55,
0x78,
0x55,
0x7d,
0xd7,
0xaf,
0xe1,
0x59,
0xe4,
0x5c,
0x65,
0xdd,
0xe7,
0x5f,
0xe8,
0x27,
0xc0,
0x69,
0x41,
0x6a,
0xc3,
0xeb,
0xc5,
0x6c,
0xc9,
0x1d,
0x2d,
0xee,
0xa9,
0x41,
0xaf,
0xed,
0x41,
0xed,
0x28,
0xd2,
0x7b,
0xd2,
0x7b,
0xa9,
0x5f,
0xed,
0x5f,
0xd1,
0x2d,
0xee,
0xd1,
0x41,
0x1d,
0xfc,
0xaa,
0xc6,
0xaf,
0x71,
0xc6,
0x74,
0x47,
0x77,
0x48,
0x78,
0x48,
0xf9,
0xc9,
0xfa,
0xca,
0x7b,
0xcc,
0xfc,
0xcf,
0xfc,
0x2b,
0xcc,
0x6c,
0xcc,
0x6c,
0xaa,
0x55,
0x2e,
0x7e,
0x55,
0x7e,
0x2b,
0x4b,
0xf0,
0x4b,
0xf0,
0xaa,
0x55,
0x2d,
0x7e,
0x55,
0x7e,
0x2b,
0xcc,
0xee,
0xcc,
0xee,
0xaa,
0x50,
0x6f,
0x4d,
0xf0,
0x4b,
0x71,
0xca,
0x72,
0x48,
0x74,
0x47,
0xf6,
0xc6,
0xfc,
0xc6,
0x1d,
0xee,
0x2b,
0x4e,
0xaf,
0x71,
0x4e,
0xf5,
0xcf,
0x77,
0x50,
0xd1,
0x78,
0xd2,
0xf9,
0x53,
0xfa,
0xd4,
0x7b,
0x55,
0x7b,
0xac,
0xc9,
0x4b,
0xfa,
0x4e,
0xf9,
0xd1,
0x78,
0x53,
0x77,
0x55,
0xf6,
0x56,
0xf5,
0xd7,
0xf3,
0x59,
0x72,
0x5a,
0x71,
0xdb,
0x6f,
0x5c,
0xee,
0xdd,
0x6c,
0xde,
0x69,
0x5f,
0xe7,
0x5f,
0x65,
0x5f,
0x63,
0x5f,
0x2e,
0xff,
0xff,
0xde,
0xfc,
0xdd,
0x7b,
0x5c,
0xf9,
0xdb,
0x77,
0x59,
0xf5,
0xd7,
0x74,
0x55,
0xf3,
0xd2,
0x72,
0xd1,
0x71,
0xcf,
0x2d,
0xee,
0x2d,
0x44,
0xee,
0xac,
0x50,
0x2e,
0x6f,
0xc0,
0x71,
0x2b,
0x5f,
0x74,
0x5f,
0x77,
0xac,
0xc0,
0xf9,
0x42,
0xfa,
0x44,
0x7b,
0xc5,
0xfc,
0xc6,
0x48,
0x7e,
0x4b,
0xaf,
0x60,
0x4d,
0xe2,
0x4d,
0x66,
0x4d,
0x69,
0xcc,
0xeb,
0xca,
0xed,
0x48,
0xed,
0x2b,
0xde,
0x2d,
0xee,
0xde,
0x4e,
0x1d,
0xee,
0x2d,
0x42,
0xaf,
0xf5,
0x42,
0x78,
0xc3,
0xfa,
0xc5,
0x7b,
0x47,
0xfc,
0xca,
0xcc,
0x7b,
0xd1,
0xfa,
0xd4,
0x78,
0x55,
0x77,
0x56,
0xf5,
0xd7,
0x2e,
0x63,
0x2e,
0xc6,
0xaf,
0xf5,
0xd2,
0x77,
0x53,
0xf9,
0x55,
0xfa,
0x56,
0x7b,
0xd7,
0xfc,
0xd8,
0x7d,
0xdb,
0x5f,
0xfc,
0xaf,
0x42,
0xfa,
0xc5,
0x78,
0x47,
0xf5,
0xc9,
0x72,
0xc9,
0x2d,
0xee,
0xc9,
0xee,
0x2e,
0xdb,
0xaf,
0x65,
0xdb,
0x2d,
0xf5,
0x4e,
0x72,
0x4e,
0xf0,
0xcc,
0xee,
0xc9,
0xc3,
0xf0,
0xc0,
0x71,
0x2d,
0x5f,
0x72,
0xde,
0x78,
0xdd,
0x7e,
0xdb,
0x2e,
0xe4,
0x59,
0xeb,
0xd7,
0xaf,
0xe4,
0xcf,
0x2d,
0xee,
0xcf,
0x42,
0x1d,
0x2e,
0xf0,
0xaf,
0xdb,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xc0,
0xc0,
0xc0,
0xc0,
0x1d,
0x7d,
0xa0,
0xd1,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2d,
0xf9,
0x22,
0x44,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2e,
0xe4,
0x24,
0xc0,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xaf,
0xf3,
0xa5,
0xcf,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2d,
0xf6,
0x27,
0x4b,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xaf,
0x74,
0xa9,
0xc9,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2e,
0xf6,
0xaa,
0xcf,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x71,
0x2b,
0xd7,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2d,
0x78,
0x2e,
0xc6,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0xac,
0xeb,
0xa9,
0xde,
0x1b,
0x5a,
0x9f,
0x1b,
0x12,
0x1b,
0xcc,
0x1b,
0xcf,
0x1b,
0xca,
0x66,
0x6f,
0x72,
0x1b,
0xcc,
0x1b,
0x4e,
0x1b,
0xca,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0x2b,
0xe8,
0xa0,
0xca,
0x1b,
0x5a,
0x1b,
0xe1,
0x44,
0x69,
0x4b,
0xd8,
0x1b,
0xe2,
0x44,
0x69,
0x4b,
0xd8,
0x1b,
0x12,
0x1d,
0x7b,
0x4e,
0x7b,
0x22,
0xd8,
0xfc,
0x59,
0x59,
0x7d,
0x5a,
0x5c,
0xff,
0xff,
0xdb,
0xac,
0x60,
0x59,
0xe1,
0x59,
0x63,
0xd7,
0xe4,
0x56,
0x65,
0xd4,
0x66,
0xd2,
0xe7,
0x50,
0x4e,
0xe8,
0x4b,
0xc9,
0xc6,
0xe7,
0xc3,
0xc0,
0x66,
0x21,
0xde,
0x65,
0xdb,
0xe4,
0xd8,
0x55,
0x53,
0x65,
0x50,
0x66,
0x4e,
0xe7,
0xcc,
0xc9,
0xe8,
0x47,
0xc6,
0xc3,
0xc0,
0xe7,
0xa0,
0xde,
0x66,
0xdb,
0xe4,
0xd8,
0x63,
0x55,
0xe1,
0x53,
0x60,
0xd2,
0x2b,
0xff,
0xff,
0xd1,
0x7d,
0x50,
0x7b,
0x4e,
0x1d,
0xac,
0xe7,
0x21,
0x53,
0xd4,
0x55,
0xd7,
0xe8,
0xd8,
0x5a,
0x69,
0xdb,
0x5c,
0x6a,
0xdd,
0xeb,
0xde,
0x6c,
0x5f,
0x6c,
0x22,
0xc0,
0xed,
0x41,
0xee,
0x42,
0x6f,
0xc3,
0xf0,
0xc3,
0x71,
0x44,
0xf3,
0xc5,
0xf5,
0xc6,
0x77,
0x47,
0xf9,
0x47,
0x7b,
0x47,
0x7e,
0x47,
0xff,
0xff,
0x47,
0xc6,
0x44,
0x7e,
0xc3,
0x7d,
0xc0,
0xfc,
0x21,
0xde,
0x7b,
0xdd,
0xfa,
0xdb,
0xf9,
0x5a,
0x78,
0x59,
0x77,
0xd8,
0xf6,
0xd8,
0xf5,
0xd7,
0x74,
0x56,
0xf3,
0x55,
0x72,
0x55,
0xf0,
0xd4,
0xee,
0x53,
0xeb,
0x53,
0x69,
0x53,
0xe7,
0x53,
0x1d,
0xf3,
0xdd,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x60,
0xc0,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0x66,
0x5c,
0x4b,
0xff,
0xff,
0x1b,
0xe2,
0x66,
0x5c,
0x4b,
0xff,
0xff,
0x1b,
0x12,
0x1d,
0x2b,
0x6f,
0x22,
0xd1,
0x6f,
0xa0,
0xca,
0xf0,
0xca,
0x71,
0x4b,
0xf3,
0x4b,
0xf5,
0xcc,
0x77,
0xcc,
0x78,
0x4d,
0xfa,
0x4d,
0x7b,
0x4e,
0x7b,
0x22,
0xd8,
0xfa,
0xd7,
0x56,
0xf9,
0x56,
0x78,
0x55,
0x77,
0xd4,
0xf6,
0xd4,
0xf5,
0x53,
0x74,
0x53,
0xf3,
0xd2,
0x71,
0xd2,
0xd1,
0xf0,
0xd1,
0x6f,
0xd1,
0x1d,
0xf3,
0x21,
0x55,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0xde,
0x48,
0x48,
0x7d,
0x1b,
0xe2,
0xde,
0x48,
0x48,
0x7d,
0x1b,
0x12,
0x1d,
0xe2,
0x22,
0xd2,
0xe2,
0xa0,
0x4b,
0x63,
0x4b,
0xe4,
0xca,
0x65,
0xca,
0xe7,
0xca,
0xe8,
0xca,
0x6a,
0xca,
0xeb,
0xca,
0x6c,
0xca,
0xed,
0xca,
0x6f,
0xca,
0x6f,
0x22,
0xd1,
0xed,
0xd1,
0x6c,
0x50,
0x6a,
0x50,
0xe8,
0xd1,
0x66,
0xd1,
0x65,
0xd2,
0xe2,
0xd2,
0x1d,
0xe8,
0x21,
0x53,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0x7d,
0x60,
0xc3,
0x78,
0x1b,
0xe2,
0x7d,
0x60,
0xc3,
0x78,
0x1b,
0x12,
0x1d,
0xaa,
0xf6,
0x22,
0xde,
0xf6,
0xa0,
0x4e,
0x77,
0x4e,
0xf9,
0x4d,
0xfa,
0x4d,
0xfc,
0xcc,
0x7d,
0xcc,
0xff,
0xff,
0x4b,
0x2b,
0x60,
0x4b,
0xe2,
0x4b,
0xe2,
0x22,
0x53,
0xe1,
0x53,
0x60,
0xd4,
0xaa,
0xff,
0xff,
0x55,
0x7e,
0x56,
0x7d,
0x56,
0xfc,
0xd7,
0x7b,
0xd8,
0xfa,
0x59,
0xf9,
0x5a,
0x5c,
0x78,
0xdd,
0x77,
0xdd,
0x5f,
0xf6,
0xde,
0x1d,
0xfa,
0x21,
0xd4,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0x56,
0xf6,
0x63,
0x65,
0x1b,
0xe2,
0x56,
0xf6,
0x63,
0x65,
0x1b,
0x12,
0x1d,
0x69,
0x22,
0xd7,
0x69,
0xa0,
0x55,
0x6a,
0xd4,
0x6c,
0x53,
0x53,
0xee,
0xd2,
0x6f,
0xd1,
0xf0,
0x50,
0x71,
0x50,
0x72,
0x50,
0xf3,
0xcf,
0xf5,
0x4e,
0xf6,
0x4e,
0xf6,
0x22,
0xde,
0x74,
0xdd,
0xf3,
0xdd,
0x72,
0xdd,
0x71,
0x5c,
0xf0,
0x5c,
0xdb,
0x6f,
0xdb,
0xee,
0x5a,
0xed,
0x59,
0x6c,
0x59,
0xeb,
0x59,
0x6a,
0xd8,
0x69,
0xd7,
0x1d,
0xf0,
0x41,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0xdb,
0x6f,
0xc9,
0xc0,
0x1b,
0xe2,
0xdb,
0x6f,
0xc9,
0xc0,
0x1b,
0x12,
0x1d,
0x69,
0xa0,
0x55,
0x69,
0x22,
0xd7,
0xe8,
0x56,
0xe7,
0x56,
0x66,
0x55,
0x65,
0xd4,
0xe4,
0x53,
0x63,
0x53,
0xd2,
0xe2,
0xd1,
0xe1,
0x50,
0x60,
0x50,
0xcf,
0xa9,
0xff,
0xff,
0x4e,
0x7e,
0x4d,
0x4d,
0x7d,
0x4b,
0xca,
0xfc,
0xc9,
0x47,
0xc6,
0xc5,
0x7d,
0x44,
0x42,
0x7e,
0xc0,
0xff,
0xff,
0x21,
0xde,
0xaa,
0x60,
0x5c,
0x5a,
0xd7,
0x55,
0x53,
0xd1,
0xa9,
0xff,
0xff,
0xcf,
0x7e,
0xcc,
0x7d,
0x4b,
0xfc,
0x48,
0xc6,
0xc3,
0x7d,
0xc0,
0x7e,
0xa0,
0xde,
0xff,
0xff,
0xdd,
0xaa,
0x60,
0xdb,
0xe2,
0x59,
0x63,
0xd8,
0x65,
0xd7,
0x66,
0x56,
0x69,
0x55,
0x1d,
0xe1,
0x22,
0xc6,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0xa3,
0x78,
0xaf,
0x41,
0x1b,
0x5a,
0x1b,
0x12,
0x1d,
0xaa,
0x69,
0x24,
0x4b,
0xeb,
0x4b,
0x6c,
0xcc,
0xcf,
0xed,
0xd1,
0xee,
0xd2,
0xac,
0x66,
0xa5,
0x44,
0xe8,
0xc5,
0x47,
0xaa,
0xf0,
0x5a,
0xee,
0xdb,
0xed,
0xdd,
0x6c,
0xa6,
0xc0,
0x69,
0xc0,
0x69,
0xa5,
0xdd,
0x6a,
0x5a,
0xd1,
0xcf,
0x69,
0x4e,
0xca,
0x6c,
0xca,
0xed,
0x4d,
0xcf,
0x6f,
0x50,
0x2b,
0x60,
0xca,
0x60,
0x24,
0xdd,
0xaa,
0x71,
0x59,
0xee,
0x59,
0xed,
0x5a,
0x6c,
0xdd,
0x5f,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x69,
0x5f,
0x4b,
0x1d,
0x2b,
0xe4,
0xde,
0xf6,
0xa5,
0xc3,
0xe4,
0xc9,
0xe4,
0x24,
0xde,
0x1d,
0xaa,
0x7d,
0xa6,
0x53,
0x1d,
0x6a,
0xcc,
0x69,
0xd2,
0xd7,
0xeb,
0xdd,
0x6f,
0x27,
0x42,
0x74,
0xc5,
0xfa,
0x47,
0xff,
0xff,
0x47,
0x1d,
0x2b,
0xe4,
0xa6,
0x56,
0x1d,
0x60,
0x27,
0x47,
0x66,
0x47,
0xeb,
0xc6,
0xf0,
0x42,
0x74,
0xa6,
0xdd,
0xf5,
0xd7,
0x1d,
0xd7,
0xf6,
0xd4,
0xf5,
0x50,
0x72,
0x4d,
0xf0,
0xca,
0xf5,
0xca,
0xf6,
0x48,
0x74,
0xc6,
0x72,
0xc3,
0x6f,
0xa5,
0x5f,
0xdd,
0xed,
0xdd,
0x6c,
0x5f,
0xeb,
0xa6,
0xc0,
0x6a,
0x41,
0xa9,
0xfa,
0x41,
0x78,
0xc0,
0x78,
0xa5,
0xde,
0x77,
0x5c,
0xf5,
0x5c,
0xf5,
0xa6,
0xc0,
0xf6,
0x44,
0xca,
0xf5,
0x4d,
0x50,
0x77,
0x50,
0x78,
0x4d,
0xf9,
0x4b,
0xfa,
0xca,
0xaa,
0x6a,
0xca,
0xcc,
0x1d,
0x6f,
0x4b,
0x2b,
0xeb,
0x4b,
0xed,
0x4d,
0x6f,
0x50,
0xd4,
0xed,
0x59,
0x69,
0x5c,
0xe7,
0xdd,
0x66,
0xde,
0xe2,
0x5f,
0xaa,
0xf9,
0x5f,
0xf5,
0xde,
0xf3,
0xdd,
0xf0,
0xdb,
0xee,
0x5a,
0x6c,
0xd7,
0xeb,
0xd4,
0xcf,
0x6c,
0x4d,
0xee,
0x4b,
0xf0,
0x4b,
0x1d,
0xa9,
0xf5,
0x27,
0xc5,
0x77,
0xc5,
0x78,
0xc9,
0xf9,
0x4b,
0x2b,
0x69,
0x4b,
0x6c,
0xc9,
0xed,
0x47,
0x6f,
0x47,
0xf0,
0xca,
0x72,
0x4d,
0x74,
0xcf,
0xf6,
0xd2,
0x53,
0xd4,
0x6f,
0xd4,
0xf3,
0xd8,
0xf5,
0xdb,
0xf6,
0xde,
0xf6,
0x28,
0xc3,
0xf5,
0x48,
0x72,
0x4b,
0xf0,
0x4d,
0xee,
0xcf,
0x6c,
0x50,
0x69,
0xd1,
0xe7,
0xd2,
0xaa,
0xfa,
0xd2,
0x77,
0xd1,
0xf3,
0xcf,
0xf0,
0x4d,
0xee,
0x4b,
0xeb,
0xc9,
0x69,
0xc5,
0xe7,
0xc0,
0xe7,
0x27,
0x59,
0x69,
0x56,
0x6a,
0xd4,
0xa9,
0xf9,
0xd4,
0x78,
0x55,
0x56,
0x77,
0xd8,
0x5a,
0xf5,
0x5a,
0xd7,
0xf6,
0x53,
0xcc,
0x4b,
0xf5,
0xca,
0xc5,
0x1d,
0xaa,
0xf0,
0x55,
0x2b,
0x6a,
0x55,
0x6c,
0x56,
0xee,
0xd8,
0x6f,
0xdb,
0x6f,
0x28,
0xc0,
0xed,
0x42,
0xeb,
0xc5,
0xe7,
0x47,
0x65,
0x48,
0xe1,
0xc9,
0xaa,
0x78,
0xc9,
0xf6,
0x48,
0xf3,
0xc6,
0x6f,
0x44,
0xed,
0x42,
0xeb,
0xc0,
0x6a,
0x27,
0xdb,
0xeb,
0xd8,
0xed,
0x56,
0xf0,
0x55,
0x1d,
0x69,
0x28,
0xd2,
0x6c,
0xd2,
0xd4,
0xed,
0x56,
0xee,
0xd8,
0xac,
0x63,
0xd8,
0xe4,
0xd7,
0x65,
0x55,
0x66,
0x53,
0xe8,
0xd2,
0x55,
0x69,
0xd7,
0x6a,
0x5a,
0xeb,
0xdb,
0x6c,
0xdd,
0x6c,
0xa9,
0xc0,
0xaa,
0xee,
0xc0,
0xed,
0x41,
0x6c,
0xc3,
0xc6,
0xe8,
0xc6,
0xc3,
0x69,
0xc0,
0x69,
0x28,
0xd8,
0xe8,
0xd2,
0x1d,
0x2b,
0x65,
0xaa,
0xc9,
0x65,
0xa9,
0xcf,
0x60,
0xcf,
0xaa,
0x7d,
0xcf,
0xfa,
0x50,
0xf6,
0xd1,
0x74,
0xd2,
0x72,
0xd4,
0xf0,
0x56,
0xee,
0xd8,
0x5a,
0xee,
0xaa,
0xc0,
0x6f,
0x42,
0xf0,
0x44,
0x72,
0xc6,
0xf3,
0x48,
0xc9,
0x72,
0xc9,
0xee,
0x48,
0x6c,
0xc6,
0xeb,
0xc5,
0x6a,
0x42,
0xe8,
0xa9,
0x5f,
0x5a,
0x55,
0x69,
0xd1,
0xeb,
0x4d,
0x6f,
0xca,
0x72,
0x48,
0xf5,
0x47,
0x7b,
0xc6,
0xff,
0xff,
0xc6,
0x2b,
0x63,
0xc6,
0x6a,
0x48,
0x6f,
0xca,
0x71,
0x4d,
0x74,
0xd1,
0xf5,
0xd4,
0xf6,
0x56,
0xdd,
0x74,
0xaa,
0xc3,
0x72,
0xc5,
0xf0,
0x47,
0xee,
0xc9,
0xeb,
0xca,
0x65,
0xca,
0x1d,
0x69,
0xa9,
0xdd,
0x50,
0x6c,
0xd1,
0x6f,
0xd2,
0x72,
0x55,
0xf3,
0xd7,
0x5a,
0xdd,
0x72,
0xde,
0xf0,
0xaa,
0xc0,
0xed,
0xc0,
0x6a,
0xc0,
0x69,
0xa9,
0xdd,
0x1d,
0xaa,
0xe8,
0xaa,
0xd7,
0xeb,
0xd7,
0x6c,
0x59,
0xed,
0xdb,
0xde,
0x2b,
0xff,
0xff,
0xde,
0xac,
0x60,
0xde,
0x63,
0xdd,
0x5a,
0xd8,
0x66,
0xd8,
0xdd,
0x65,
0x5f,
0x65,
0x2b,
0x47,
0x66,
0xc9,
0xcc,
0x4e,
0x65,
0xd1,
0xdb,
0x66,
0xac,
0x41,
0x63,
0x41,
0xe2,
0x2b,
0xdb,
0xaa,
0x6f,
0xdb,
0xed,
0xdb,
0x6c,
0x5c,
0xeb,
0xde,
0x69,
0xde,
0x59,
0x6a,
0xd8,
0x56,
0x50,
0x69,
0x4e,
0xc9,
0x6a,
0x47,
0x6a,
0xaa,
0xde,
0x69,
0xd7,
0x1d,
0xee,
0x2b,
0x48,
0xac,
0xe1,
0x48,
0xe2,
0xc9,
0x63,
0x4b,
0x4e,
0xe2,
0xd1,
0xaa,
0x6f,
0xd1,
0xee,
0x50,
0xed,
0x4e,
0x6c,
0xcc,
0x4b,
0xed,
0x48,
0x1d,
0x6f,
0xac,
0xde,
0xfc,
0xde,
0x7d,
0xdd,
0x7e,
0x5c,
0x59,
0x2b,
0x60,
0x59,
0xe1,
0x5a,
0x5c,
0x60,
0xde,
0x60,
0x2d,
0x47,
0xe1,
0xc9,
0x4b,
0xaa,
0x7e,
0x4b,
0x47,
0xf0,
0x47,
0xee,
0xc6,
0xed,
0xc5,
0xeb,
0x42,
0x6a,
0xc0,
0xe8,
0xac,
0x5c,
0xd1,
0x69,
0xcf,
0xeb,
0x4b,
0xed,
0x48,
0xf0,
0xc5,
0xf3,
0xc3,
0x77,
0x41,
0xfa,
0x41,
0x2b,
0x66,
0x41,
0x6a,
0x42,
0x6f,
0xc5,
0x72,
0x47,
0x74,
0xca,
0xf6,
0x4d,
0x77,
0x50,
0x78,
0xd4,
0xf9,
0xd7,
0xdd,
0x77,
0x2d,
0x42,
0xf6,
0xc5,
0xed,
0xc5,
0xc3,
0x6f,
0x42,
0x71,
0x41,
0x72,
0xc0,
0x74,
0xac,
0xde,
0xf5,
0xdd,
0xf6,
0x5a,
0x55,
0x74,
0xd1,
0x71,
0x4e,
0xee,
0xcc,
0x6a,
0xca,
0xe7,
0xc9,
0xaa,
0xf9,
0xc9,
0xf6,
0xca,
0x72,
0xcc,
0x6f,
0x4e,
0xee,
0x50,
0x6c,
0x55,
0xeb,
0xd7,
0x5a,
0x6c,
0xdd,
0x6f,
0xde,
0x1d,
0x6c,
0x2d,
0x50,
0x77,
0x50,
0x53,
0xf3,
0x53,
0xf0,
0xd4,
0xee,
0x56,
0x6c,
0xd8,
0xeb,
0x5a,
0xdd,
0xeb,
0x2e,
0xc0,
0xed,
0x41,
0x6f,
0x44,
0x72,
0xc5,
0xf5,
0xc5,
0xf9,
0x42,
0xfc,
0x2d,
0xde,
0x2b,
0x60,
0xd7,
0xe4,
0xd2,
0x66,
0x50,
0xf0,
0x50,
0x74,
0x53,
0x77,
0xd7,
0xf9,
0x5c,
0xf9,
0x2e,
0xc0,
0x78,
0xc5,
0xf6,
0x48,
0xed,
0x48,
0xc6,
0x6f,
0xc5,
0xf3,
0xc3,
0xf5,
0x42,
0xf6,
0x2d,
0xde,
0xf5,
0x5a,
0xf3,
0xd8,
0xf0,
0xd7,
0xee,
0xd7,
0xeb,
0xd8,
0xe8,
0xdd,
0x66,
0x2e,
0xc0,
0xe2,
0x47,
0xaa,
0x7d,
0x4b,
0x7b,
0xcc,
0x72,
0xcc,
0xed,
0x48,
0x6a,
0xc5,
0x69,
0x42,
0xe8,
0x2d,
0xde,
0xd8,
0x69,
0x55,
0x6c,
0x50,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xc0,
0xc0,
0xc0,
0xc0,
0x1d,
0x2b,
0x63,
0xa5,
0x4e,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xaa,
0x78,
0xa6,
0xc5,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x7d,
0x27,
0x42,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xf6,
0x50,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x7b,
0x28,
0xcc,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2b,
0x60,
0xdb,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xaa,
0x74,
0xa9,
0xcc,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2b,
0xe1,
0x2b,
0xc3,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xaa,
0x7e,
0xac,
0x44,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x77,
0x2d,
0x42,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x7e,
0x2e,
0x44,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xf0,
0x24,
0x56,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2b,
0xe2,
0x2b,
0x56,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xf6,
0xac,
0x53,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x72,
0x2d,
0xc3,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xaa,
0x74,
0xd2,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x2b,
0x74,
0x2e,
0xc5,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x77,
0x2d,
0x59,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x69,
0xaa,
0xc5,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0xa9,
0x60,
0xa0,
0xc0,
0x1b,
0x5a,
0x9f,
0x1b,
0x12,
0xc3,
0x6f,
0xf0,
0xf9,
0x72,
0x69,
0xe7,
0xe8,
0x74,
0xa0,
0x28,
0x1b,
0xc3,
0xc0,
0x1b,
0x42,
0xa9,
0xa0,
0xb2,
0x30,
0xb1,
0xb8,
0xa0,
0xc9,
0xd2,
0x41,
0xd4,
0x41,
0x2e,
0xcf,
0x4e,
0xcc,
0xc9,
0x4e,
0xc5,
0x2e,
0xa0,
0xd4,
0xe8,
0x69,
0xf3,
0xa0,
0x74,
0x65,
0x72,
0xed,
0x69,
0xee,
0xe1,
0x6c,
0xa0,
0x69,
0xf3,
0xa0,
0x72,
0x65,
0x6c,
0x65,
0xe1,
0xf3,
0x65,
0xe4,
0xa0,
0xf5,
0xee,
0xe4,
0x65,
0x72,
0x8d,
0x74,
0xe8,
0x65,
0xa0,
0x47,
0x4e,
0x55,
0xa0,
0x50,
0xf5,
0xe2,
0x6c,
0x69,
0x63,
0xa0,
0xcc,
0x69,
0x63,
0x65,
0xee,
0xf3,
0x65,
0x2e,
0xa0,
0xd2,
0xf5,
0xee,
0xa0,
0x74,
0xe8,
0x65,
0xa0,
0xf0,
0x72,
0x6f,
0xe7,
0x72,
0xe1,
0xed,
0xa0,
0x47,
0x50,
0xcc,
0xac,
0xa0,
0x66,
0x6f,
0x72,
0xa0,
0xe4,
0x65,
0x74,
0xe1,
0x69,
0x6c,
0xf3,
0x2e,
0x1d,
0x1b,
0x12,
0x28,
0xf0,
0x2e,
0x48,
0x1d,
0xa9,
0x74,
0xa0,
0xc0,
0x74,
0xaf,
0x5f,
0x1d,
0x28,
0x6c,
0xa0,
0xc0,
0x6c,
0xaf,
0x5f,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x1b,
0x03
};

#endif /* SPLASH_H */
