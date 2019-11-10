// license:BSD-3-Clause
// copyright-holders:Robbbert
#include "../mame/drivers/tmnt.cpp"

ROM_START( ssridersaex )
	ROM_REGION( 0xc0000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "064eac02.8e-ex",  0x000000, 0x40000, CRC(536d4a79) SHA1(dec7f827e3a1300ee32e6134b8141ae99a89b50a) )
	ROM_LOAD16_BYTE( "064eac03.8g-ex",  0x000001, 0x40000, CRC(8ea4c0e8) SHA1(c971df7fdaa801c6351a5df401a7528f000bee06) )
	ROM_LOAD16_BYTE( "064eab04.10e", 0x080000, 0x20000, CRC(ef2315bd) SHA1(2c8b11321cb5fdb78d760fabca666c0d8cc5b298) )
	ROM_LOAD16_BYTE( "064eab05.10g", 0x080001, 0x20000, CRC(51d6fbc4) SHA1(e80de7d155b7f263c48ef4ae2702059be3c18e76) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "064e01.2f",   0x0000, 0x10000, CRC(44b9bc52) SHA1(4654d6e14c6956c40a19cb41155accb63f0da338) )

	ROM_REGION( 0x100000, "k052109", 0 )
	ROM_LOAD32_WORD( "064e12.16k",   0x000000, 0x080000, CRC(e2bdc619) SHA1(04449deb267b0beacfa33640b593eb16194aa0d9) )
	ROM_LOAD32_WORD( "064e11.12k",   0x000002, 0x080000, CRC(2d8ca8b0) SHA1(7c882f79c2402cf75979c681071007d76e4db9ae) )

	ROM_REGION( 0x200000, "k053245", 0 )
	ROM_LOAD32_WORD( "064e09.7l", 0x000000, 0x100000, CRC(4160c372) SHA1(0b36181e5ccd785c7fb89b9f41e458066a42c3b0) )
	ROM_LOAD32_WORD( "064e07.3l", 0x000002, 0x100000, CRC(64dd673c) SHA1(bea4d17a71dd21c635866ee69b4892dc9d0ab455) )

	ROM_REGION( 0x100000, "k053260", 0 )
	ROM_LOAD( "064e06.1d",    0x0000, 0x100000, CRC(59810df9) SHA1(a0affc6330bdbfab1447dc0cf13c20ff708c2c71) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "ssriders_abd.nv", 0x0000, 0x080, CRC(bfdafedf) SHA1(bc786d4fb3495a6baf2ae13c19392c6740a2be6d) )
	//ROM_LOAD( "ssriders_eac.nv", 0x0000, 0x080, CRC(f6d641a7) SHA1(6c680d49e1b07a47b29ff263a6009d226bd120cf) )
ROM_END


//    YEAR, NAME,        PARENT,   MACHINE,  INPUT,     INIT,          MONITOR,COMPANY,FULLNAME,FLAGS
GAME( 2009, ssridersaex, ssriders, ssriders, ssriders,  tmnt_state, empty_init, ROT0,   "Pipi899","Sunset Riders (EX Super Version 2009-07-28)", MACHINE_SUPPORTS_SAVE )


// PSmame (c) gaston90 used with permission

 /****************************************************
         Proyecto Shadows Mame Build Plus
*****************************************************/
 /*************
 Sunset Riders
***************/

ROM_START( ssriderseaas01 )
	ROM_REGION( 0xc0000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "064eaa02_ps01.8e",   0x000000, 0x40000, CRC(f6bce510) SHA1(3c46487c4bd591fe14248344ac2563beb1437769) )
	ROM_LOAD16_BYTE( "064eaa03_ps01.8g",   0x000001, 0x40000, CRC(9e998ebe) SHA1(683d75bcfb8b8f87996fe8aadde4d1c600b409df) )
	ROM_LOAD16_BYTE( "064eaa04_ps01.10e",  0x080000, 0x20000, CRC(06755c89) SHA1(0e19d1147407b8062335c0529ae8f7c01b634e01) )
	ROM_LOAD16_BYTE( "064eaa05_ps01.10g",  0x080001, 0x20000, CRC(0aad4619) SHA1(98678d79323f5cc439dd186aa45ab3fb2e7d1515) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "064eaa01.2f",   0x0000, 0x10000, CRC(bce45d82) SHA1(7f6d17fad0b556243c59d25a94925d259d98d81a) )

	ROM_REGION( 0x100000, "k052109", 0 ) 
	ROM_LOAD32_WORD( "064e12.16k",   0x000000, 0x080000, CRC(e2bdc619) SHA1(04449deb267b0beacfa33640b593eb16194aa0d9) )
	ROM_LOAD32_WORD( "064e11.12k",   0x000002, 0x080000, CRC(2d8ca8b0) SHA1(7c882f79c2402cf75979c681071007d76e4db9ae) )

	ROM_REGION( 0x200000, "k053245", 0 )  
	ROM_LOAD32_WORD( "064e09.7l", 0x000000, 0x100000, CRC(4160c372) SHA1(0b36181e5ccd785c7fb89b9f41e458066a42c3b0) )
	ROM_LOAD32_WORD( "064e07.3l", 0x000002, 0x100000, CRC(64dd673c) SHA1(bea4d17a71dd21c635866ee69b4892dc9d0ab455) )

	ROM_REGION( 0x100000, "k053260", 0 )
	ROM_LOAD( "064e06.1d",    0x0000, 0x100000, CRC(59810df9) SHA1(a0affc6330bdbfab1447dc0cf13c20ff708c2c71) )

	ROM_REGION( 0x80, "eeprom", 0 ) 
	ROM_LOAD( "ssriders_eaa.nv", 0x0000, 0x080, CRC(74a45ef5) SHA1(da01f14684315bfb5c180f0c64a14350c34ae945) )
ROM_END

ROM_START( ssriderseaas02 )
	ROM_REGION( 0xc0000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "064eaa02_ps02.8e",   0x000000, 0x40000, CRC(734f4b4c) SHA1(a38d27d38759e3811c54e4921186c91a762eaa62) )
	ROM_LOAD16_BYTE( "064eaa03_ps02.8g",   0x000001, 0x40000, CRC(d50e01fd) SHA1(8070090ee0da5e57d6df042da8926dd322629bfd) )
	ROM_LOAD16_BYTE( "064eaa04_ps02.10e",  0x080000, 0x20000, CRC(56bb2e75) SHA1(78cf0cc1a529a5f9e37249d8480aa7476e338099) )
	ROM_LOAD16_BYTE( "064eaa05_ps01.10g",  0x080001, 0x20000, CRC(0aad4619) SHA1(98678d79323f5cc439dd186aa45ab3fb2e7d1515) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "064eaa01.2f",   0x0000, 0x10000, CRC(bce45d82) SHA1(7f6d17fad0b556243c59d25a94925d259d98d81a) )

	ROM_REGION( 0x100000, "k052109", 0 ) 
	ROM_LOAD32_WORD( "064e12.16k",   0x000000, 0x080000, CRC(e2bdc619) SHA1(04449deb267b0beacfa33640b593eb16194aa0d9) )
	ROM_LOAD32_WORD( "064e11.12k",   0x000002, 0x080000, CRC(2d8ca8b0) SHA1(7c882f79c2402cf75979c681071007d76e4db9ae) )

	ROM_REGION( 0x200000, "k053245", 0 )  
	ROM_LOAD32_WORD( "064e09.7l", 0x000000, 0x100000, CRC(4160c372) SHA1(0b36181e5ccd785c7fb89b9f41e458066a42c3b0) )
	ROM_LOAD32_WORD( "064e07.3l", 0x000002, 0x100000, CRC(64dd673c) SHA1(bea4d17a71dd21c635866ee69b4892dc9d0ab455) )

	ROM_REGION( 0x100000, "k053260", 0 )
	ROM_LOAD( "064e06.1d",    0x0000, 0x100000, CRC(59810df9) SHA1(a0affc6330bdbfab1447dc0cf13c20ff708c2c71) )

	ROM_REGION( 0x80, "eeprom", 0 ) 
	ROM_LOAD( "ssriders_eaa.nv", 0x0000, 0x080, CRC(74a45ef5) SHA1(da01f14684315bfb5c180f0c64a14350c34ae945) )
ROM_END

 /****************************
 Teenage Mutant Ninja Turtles
*******************************/

ROM_START( tmnt2s01 )
	ROM_REGION( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "063adahc12.8e",  0x000000, 0x20000, CRC(651daf6f) SHA1(3abd95fe82566f96efc3f59867504c026b94c5b9) )
	ROM_LOAD16_BYTE( "063adahc13.8g",  0x000001, 0x20000, CRC(b0011b05) SHA1(d993520bcfce680c3d7a63f530d2bc7c18a3d143) )
	ROM_LOAD16_BYTE( "063ada04.10e", 0x040000, 0x20000, CRC(05ad187a) SHA1(27a36a02ef792d87ffa2364537c42b6c50d6e4f0) )
	ROM_LOAD16_BYTE( "063ada05.10g", 0x040001, 0x20000, CRC(d4826547) SHA1(ffee07be64469fa386a0979352b4fe20c352fee4) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "063b01.2f", 0x0000, 0x10000, CRC(364f548a) SHA1(e0636e27d4fc48b2ccb1417b63d2b68d9e272c06) )

	ROM_REGION( 0x100000, "k052109", 0 )
	ROM_LOAD32_WORD( "063b12.16k", 0x000000, 0x080000, CRC(d3283d19) SHA1(49e4daa9cbe4d99bf71fcee6237cb434a0d55312) )
	ROM_LOAD32_WORD( "063b11.12k", 0x000002, 0x080000, CRC(6ebc0c15) SHA1(e6848405076937fbf8ec6d318293a0ff922725f4) )

	ROM_REGION( 0x400000, "k053245", 0 )
	ROM_LOAD32_WORD( "063b09.7l", 0x000000, 0x100000, CRC(2d7a9d2a) SHA1(a26f9c1a07152bc8c7bcd797d4485bf848f5e2a0) )
	ROM_LOAD32_WORD( "063b07.3l", 0x000002, 0x100000, CRC(d9bee7bf) SHA1(7bbb65138fbd216b80412783e6f0072742101440) )
	ROM_LOAD32_WORD( "063b10.7k", 0x200000, 0x080000, CRC(f2dd296e) SHA1(a2aad10bfb0904dd73c2ee11049648c94de7f4d5) )
	ROM_LOAD32_WORD( "063b08.3k", 0x200002, 0x080000, CRC(3b1ae36f) SHA1(9e69cae8b517497ac77c4d148f56f2bb6a23de89) )

	ROM_REGION( 0x200000, "k053260", 0 )
	ROM_LOAD( "063b06.1d",  0x0000, 0x200000, CRC(1e510aa5) SHA1(02b9bd6bb6b098026a620e4d671c40a31ad9e318) )

	ROM_REGION( 0x80, "eeprom", 0 )
	ROM_LOAD( "tmnt2_ada.nv", 0x0000, 0x080, CRC(063068a0) SHA1(c1da5319428fd8fb60305a2d7cc166596b2fe5a4) )
ROM_END

ROM_START( tmnt2s02 )
	ROM_REGION( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "063adahc22.8e",  0x000000, 0x20000, CRC(b29d697d) SHA1(9bbe7859da33450417f14bced76c75b1c5e83092) )
	ROM_LOAD16_BYTE( "063adahc23.8g",  0x000001, 0x20000, CRC(a633caee) SHA1(4ca8e1f41189d82c68c0759ac1ac354732296fa2) )
	ROM_LOAD16_BYTE( "063ada04.10e", 0x040000, 0x20000, CRC(05ad187a) SHA1(27a36a02ef792d87ffa2364537c42b6c50d6e4f0) )
	ROM_LOAD16_BYTE( "063ada05.10g", 0x040001, 0x20000, CRC(d4826547) SHA1(ffee07be64469fa386a0979352b4fe20c352fee4) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "063b01.2f", 0x0000, 0x10000, CRC(364f548a) SHA1(e0636e27d4fc48b2ccb1417b63d2b68d9e272c06) )

	ROM_REGION( 0x100000, "k052109", 0 )
	ROM_LOAD32_WORD( "063b12.16k", 0x000000, 0x080000, CRC(d3283d19) SHA1(49e4daa9cbe4d99bf71fcee6237cb434a0d55312) )
	ROM_LOAD32_WORD( "063b11.12k", 0x000002, 0x080000, CRC(6ebc0c15) SHA1(e6848405076937fbf8ec6d318293a0ff922725f4) )

	ROM_REGION( 0x400000, "k053245", 0 )
	ROM_LOAD32_WORD( "063b09.7l", 0x000000, 0x100000, CRC(2d7a9d2a) SHA1(a26f9c1a07152bc8c7bcd797d4485bf848f5e2a0) )
	ROM_LOAD32_WORD( "063b07.3l", 0x000002, 0x100000, CRC(d9bee7bf) SHA1(7bbb65138fbd216b80412783e6f0072742101440) )
	ROM_LOAD32_WORD( "063b10.7k", 0x200000, 0x080000, CRC(f2dd296e) SHA1(a2aad10bfb0904dd73c2ee11049648c94de7f4d5) )
	ROM_LOAD32_WORD( "063b08.3k", 0x200002, 0x080000, CRC(3b1ae36f) SHA1(9e69cae8b517497ac77c4d148f56f2bb6a23de89) )

	ROM_REGION( 0x200000, "k053260", 0 )
	ROM_LOAD( "063b06.1d",  0x0000, 0x200000, CRC(1e510aa5) SHA1(02b9bd6bb6b098026a620e4d671c40a31ad9e318) )

	ROM_REGION( 0x80, "eeprom", 0 )
	ROM_LOAD( "tmnt2_ada.nv", 0x0000, 0x080, CRC(063068a0) SHA1(c1da5319428fd8fb60305a2d7cc166596b2fe5a4) )
ROM_END

ROM_START( tmnt2s03 )
	ROM_REGION( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "063ada02hc01.8e",  0x000000, 0x20000, CRC(45109177) SHA1(9c264d80e9cabb3529acf5860d7730b4f1cd1bfe) )
	ROM_LOAD16_BYTE( "063ada03hc01.8g",  0x000001, 0x20000, CRC(cf50ffc3) SHA1(4e84705582014f264b67a1982dd40930e61479e8) )
	ROM_LOAD16_BYTE( "063ada04.10e", 0x040000, 0x20000, CRC(05ad187a) SHA1(27a36a02ef792d87ffa2364537c42b6c50d6e4f0) )
	ROM_LOAD16_BYTE( "063ada05.10g", 0x040001, 0x20000, CRC(d4826547) SHA1(ffee07be64469fa386a0979352b4fe20c352fee4) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "063b01.2f", 0x0000, 0x10000, CRC(364f548a) SHA1(e0636e27d4fc48b2ccb1417b63d2b68d9e272c06) )

	ROM_REGION( 0x100000, "k052109", 0 )
	ROM_LOAD32_WORD( "063b12.16k", 0x000000, 0x080000, CRC(d3283d19) SHA1(49e4daa9cbe4d99bf71fcee6237cb434a0d55312) )
	ROM_LOAD32_WORD( "063b11.12k", 0x000002, 0x080000, CRC(6ebc0c15) SHA1(e6848405076937fbf8ec6d318293a0ff922725f4) )

	ROM_REGION( 0x400000, "k053245", 0 )
	ROM_LOAD32_WORD( "063b09.7l", 0x000000, 0x100000, CRC(2d7a9d2a) SHA1(a26f9c1a07152bc8c7bcd797d4485bf848f5e2a0) )
	ROM_LOAD32_WORD( "063b07.3l", 0x000002, 0x100000, CRC(d9bee7bf) SHA1(7bbb65138fbd216b80412783e6f0072742101440) )
	ROM_LOAD32_WORD( "063b10.7k", 0x200000, 0x080000, CRC(f2dd296e) SHA1(a2aad10bfb0904dd73c2ee11049648c94de7f4d5) )
	ROM_LOAD32_WORD( "063b08.3k", 0x200002, 0x080000, CRC(3b1ae36f) SHA1(9e69cae8b517497ac77c4d148f56f2bb6a23de89) )

	ROM_REGION( 0x200000, "k053260", 0 )
	ROM_LOAD( "063b06.1d",  0x0000, 0x200000, CRC(1e510aa5) SHA1(02b9bd6bb6b098026a620e4d671c40a31ad9e318) )

	ROM_REGION( 0x80, "eeprom", 0 )
	ROM_LOAD( "tmnt2_ada.nv", 0x0000, 0x080, CRC(063068a0) SHA1(c1da5319428fd8fb60305a2d7cc166596b2fe5a4) )
ROM_END

/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// Sunset Riders
GAME( 2019, ssriderseaas01, ssriders, ssriders, ssridr4p,  tmnt_state, empty_init, ROT0,   "hack",  "Sunset Riders (1V4 Edition 2019-07-28)", MACHINE_IMPERFECT_GRAPHICS | MACHINE_SUPPORTS_SAVE )
GAME( 2019, ssriderseaas02, ssriders, ssriders, ssridr4p,  tmnt_state, empty_init, ROT0,   "hack",  "Sunset Riders (The Hardest Version In Two Weeks 2019-04-20)", MACHINE_IMPERFECT_GRAPHICS | MACHINE_SUPPORTS_SAVE )
// Teenage Mutant Ninja Turtles
GAME( 1991, tmnt2s01,       tmnt2,    tmnt2,    ssrid4ps,  tmnt_state, empty_init, ROT0,   "hack",  "Teenage Mutant Ninja Turtles (Ex Super Version)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, tmnt2s02,       tmnt2,    tmnt2,    ssrid4ps,  tmnt_state, empty_init, ROT0,   "hack",  "Teenage Mutant Ninja Turtles (Start Change Char)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, tmnt2s03,       tmnt2,    tmnt2,    ssrid4ps,  tmnt_state, empty_init, ROT0,   "hack",  "Teenage Mutant Ninja Turtles (Cowabunga Mode)", MACHINE_SUPPORTS_SAVE )