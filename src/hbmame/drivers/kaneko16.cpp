// license:BSD-3-Clause
// copyright-holders:Robbbert
#include "../mame/drivers/kaneko16.cpp"

ROM_START( fjbusterbh )
	ROM_REGION( 0x040000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "fbbh030a.u61", 0x000000, 0x020000, CRC(c3a66037) SHA1(4ca1b440ca822d6c6adecb5c0a3d83126bc775a2) )
	ROM_LOAD16_BYTE( "fbbh031j.u62", 0x000001, 0x020000, CRC(c104ca05) SHA1(6247ab05c6c88352a75d606961b98cd957709590) )

	ROM_REGION( 0x020000, "calc3_rom", 0 )
	ROM_LOAD( "fb040e.u33",  0x000000, 0x020000, CRC(299d0746) SHA1(67fe3a47ab01fa02ce2bb5836c2041986c19d875) )

	ROM_REGION( 0x1000000, "kan_spr", ROMREGION_ERASEFF )
	ROM_LOAD( "fb-020a.u1", 0x000000, 0x100000, CRC(87e55c6d) SHA1(87886c045d7c30b8dee3c8fb0bf8f2cdbc5fd7fb) )
	ROM_LOAD( "fb020b.u2",  0x100000, 0x100000, CRC(276b9d7b) SHA1(7a154f65b4737f2b6ac8effa3352711079f571dc) )
	ROM_LOAD( "fb021a.u3",  0x200000, 0x100000, CRC(7da15d37) SHA1(345cf2242e8210a697294a45197f2b3b974de885) )
	ROM_LOAD( "fb021b.u4",  0x300000, 0x100000, CRC(6a512d7b) SHA1(7fc3002d23262a9a590a283ea9e111e38d889ef2) )
	ROM_LOAD( "fb-22a.u5",  0x400000, 0x100000, CRC(9039e5d3) SHA1(222452cd7947f7c99c68e495835cca62e0449b5c) )
	ROM_LOAD( "fb-22b.u6",  0x500000, 0x100000, CRC(96ac9e54) SHA1(2b066375963dc57fe2ce89d65f6c0a9d183a838d) )
	ROM_LOAD( "fb023.u7",   0x600000, 0x100000, CRC(132794bd) SHA1(bcc73c3183c59a4b66f79d04774773b8a9239501) )

	ROM_REGION( 0x400000, "view2_0", 0 )
	ROM_LOAD( "fb010.u65",  0x000000, 0x100000, CRC(296ffd92) SHA1(183a28e4594c428deb4726ed22d5166592b94b60) )
	ROM_LOAD( "fb011.u66",  0x100000, 0x080000, CRC(500a0367) SHA1(6dc5190f81b21f59ee56a3b2332c8d86d6599782) )

	ROM_REGION( 0x100000, "oki1", 0 )
	ROM_LOAD( "fb000j.u43",    0x000000, 0x080000, CRC(a7522555) SHA1(ea88d90dda20bc309f98a1924c41551e7708e6af) )
	ROM_LOAD( "fb001j_u.101",  0x080000, 0x080000, CRC(07d4e8e2) SHA1(0de911f452ddeb54b0b435b9c1cf5d5881175d44) )

	ROM_REGION( 0x200000, "oki2", 0 )
	ROM_LOAD( "fb-002.u45",   0x000000, 0x100000, CRC(010acc17) SHA1(2dc0897c7778eacf6bce12ff0adbadb307ea6c17) )
	ROM_LOAD( "fb-003.u44",   0x100000, 0x100000, CRC(0aea4ac5) SHA1(8f3b30e505b0ba51c140a0a2c071680d4fa05db9) )
ROM_END

ROM_START( shogwarrbh )
	ROM_REGION( 0x040000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "fbbh030a.u61", 0x000000, 0x020000, CRC(c3a66037) SHA1(4ca1b440ca822d6c6adecb5c0a3d83126bc775a2) )
	ROM_LOAD16_BYTE( "fbbh031a.u62", 0x000001, 0x020000, CRC(e382acf8) SHA1(50177a525fb6138490c70e50f5b9ae476cb8d6de) )

	ROM_REGION( 0x020000, "calc3_rom", 0 )
	ROM_LOAD( "fb040a.u33",  0x000000, 0x020000, CRC(4b62c4d9) SHA1(35c943dde70438a411714070e42a84366db5ef83) )

	ROM_REGION( 0x1000000, "kan_spr", ROMREGION_ERASEFF )
	ROM_LOAD( "fb-020a.u1", 0x000000, 0x100000, CRC(87e55c6d) SHA1(87886c045d7c30b8dee3c8fb0bf8f2cdbc5fd7fb) )
	ROM_LOAD( "fb020b.u2",  0x100000, 0x100000, CRC(276b9d7b) SHA1(7a154f65b4737f2b6ac8effa3352711079f571dc) )
	ROM_LOAD( "fb021a.u3",  0x200000, 0x100000, CRC(7da15d37) SHA1(345cf2242e8210a697294a45197f2b3b974de885) )
	ROM_LOAD( "fb021b.u4",  0x300000, 0x100000, CRC(6a512d7b) SHA1(7fc3002d23262a9a590a283ea9e111e38d889ef2) )
	ROM_LOAD( "fb-22a.u5",  0x400000, 0x100000, CRC(9039e5d3) SHA1(222452cd7947f7c99c68e495835cca62e0449b5c) )
	ROM_LOAD( "fb-22b.u6",  0x500000, 0x100000, CRC(96ac9e54) SHA1(2b066375963dc57fe2ce89d65f6c0a9d183a838d) )
	ROM_LOAD( "fb023.u7",   0x600000, 0x100000, CRC(132794bd) SHA1(bcc73c3183c59a4b66f79d04774773b8a9239501) )

	ROM_REGION( 0x400000, "view2_0", 0 )
	ROM_LOAD( "fb010.u65",  0x000000, 0x100000, CRC(296ffd92) SHA1(183a28e4594c428deb4726ed22d5166592b94b60) )
	ROM_LOAD( "fb011.u66",  0x100000, 0x080000, CRC(500a0367) SHA1(6dc5190f81b21f59ee56a3b2332c8d86d6599782) )

	ROM_REGION( 0x100000, "oki1", 0 )
	ROM_LOAD( "fb001e.u43",  0x000000, 0x080000, CRC(f524aaa1) SHA1(006a886f9df2e57c51b61c6cea70a6574fc20304) )
	ROM_LOAD( "fb000e.u42",  0x080000, 0x080000, CRC(969f1465) SHA1(4f56d1ad341b08f4db41b7ab2498740612ff7c3d) )

	ROM_REGION( 0x200000, "oki2", 0 )
	ROM_LOAD( "fb-002.u45",   0x000000, 0x100000, CRC(010acc17) SHA1(2dc0897c7778eacf6bce12ff0adbadb307ea6c17) )
	ROM_LOAD( "fb-003.u44",   0x100000, 0x100000, CRC(0aea4ac5) SHA1(8f3b30e505b0ba51c140a0a2c071680d4fa05db9) )
ROM_END

GAME( 2017, fjbusterbh, shogwarr, shogwarr, shogwarr, kaneko16_shogwarr_state, init_shogwarr, ROT0, "e107", "Fujiyama Buster (Enable Hidden Characters 2017-04-07)", MACHINE_NO_COCKTAIL | MACHINE_SUPPORTS_SAVE )
GAME( 2017, shogwarrbh, shogwarr, shogwarr, shogwarr, kaneko16_shogwarr_state, init_shogwarr, ROT0, "e107", "Shogun Warriors (Enable Hidden Characters 2017-04-02) ", MACHINE_NO_COCKTAIL | MACHINE_SUPPORTS_SAVE )


// PSmame (c) gaston90 used with permission

 /****************************************************
         Proyecto Shadows Mame Build Plus
*****************************************************/

/****************
 Shogun Warriors
*****************/

ROM_START( shogwarrs01 )
	ROM_REGION( 0x040008, "maincpu", 0 )
	ROM_LOAD16_BYTE( "fb030es01.u61", 0x000000, 0x020004, CRC(32ce7909) SHA1(9060ba40a415ef8f050caacfcd1a1e0ef3e6c6a5) )
	ROM_LOAD16_BYTE( "fb030es01.u62", 0x000001, 0x020004, CRC(228aeaf5) SHA1(40e0e40b06a5864609d840275652df5361df7f68) )

	ROM_REGION( 0x020000, "calc3_rom", 0 )
	ROM_LOAD( "fb040e.u33",  0x000000, 0x020000, CRC(299d0746) SHA1(67fe3a47ab01fa02ce2bb5836c2041986c19d875) )

	ROM_REGION( 0x1000000, "kan_spr", ROMREGION_ERASEFF )
	ROM_LOAD( "fb-020a.u1", 0x000000, 0x100000, CRC(87e55c6d) SHA1(87886c045d7c30b8dee3c8fb0bf8f2cdbc5fd7fb) )
	ROM_LOAD( "fb020b.u2",  0x100000, 0x100000, CRC(276b9d7b) SHA1(7a154f65b4737f2b6ac8effa3352711079f571dc) )
	ROM_LOAD( "fb021a.u3",  0x200000, 0x100000, CRC(7da15d37) SHA1(345cf2242e8210a697294a45197f2b3b974de885) )
	ROM_LOAD( "fb021b.u4",  0x300000, 0x100000, CRC(6a512d7b) SHA1(7fc3002d23262a9a590a283ea9e111e38d889ef2) )
	ROM_LOAD( "fb-22a.u5",  0x400000, 0x100000, CRC(9039e5d3) SHA1(222452cd7947f7c99c68e495835cca62e0449b5c) )
	ROM_LOAD( "fb-22b.u6",  0x500000, 0x100000, CRC(96ac9e54) SHA1(2b066375963dc57fe2ce89d65f6c0a9d183a838d) )
	ROM_LOAD( "fb023.u7",   0x600000, 0x100000, CRC(132794bd) SHA1(bcc73c3183c59a4b66f79d04774773b8a9239501) )

	ROM_REGION( 0x400000, "view2_0", 0 )
	ROM_LOAD( "fb010.u65",  0x000000, 0x100000, CRC(296ffd92) SHA1(183a28e4594c428deb4726ed22d5166592b94b60) )
	ROM_LOAD( "fb011.u66",  0x100000, 0x080000, CRC(500a0367) SHA1(6dc5190f81b21f59ee56a3b2332c8d86d6599782) )

	ROM_REGION( 0x100000, "oki1", 0 )
	ROM_LOAD( "fb001e.u43",  0x000000, 0x080000, CRC(f524aaa1) SHA1(006a886f9df2e57c51b61c6cea70a6574fc20304) )
	ROM_LOAD( "fb000e.u42",  0x080000, 0x080000, CRC(969f1465) SHA1(4f56d1ad341b08f4db41b7ab2498740612ff7c3d) )

	ROM_REGION( 0x200000, "oki2", 0 )
	ROM_LOAD( "fb-002.u45",   0x000000, 0x100000, CRC(010acc17) SHA1(2dc0897c7778eacf6bce12ff0adbadb307ea6c17) )
	ROM_LOAD( "fb-003.u44",   0x100000, 0x100000, CRC(0aea4ac5) SHA1(8f3b30e505b0ba51c140a0a2c071680d4fa05db9) )
ROM_END

ROM_START( bloodwars01 )
	ROM_REGION( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "ofp0f3_ps01.514", 0x000000, 0x080000, CRC(e0d56791) SHA1(275d6273525536a3db286c71ba3602a7705179ac) )
	ROM_LOAD16_BYTE( "ofp1f3_ps01.513", 0x000001, 0x080000, CRC(e9c84790) SHA1(6bd7525d7c90de1fb3ed68310298ecaa5462f659) )

	ROM_REGION( 0x020000, "mcudata", 0 )
	ROM_LOAD16_WORD_SWAP( "ofd0x3.124",  0x000000, 0x020000, CRC(399f2005) SHA1(ff0370724770c35963953fd9596d9f808ba87d8f) )


	ROM_REGION( 0x1e00000, "kan_spr", 0 )
	ROM_LOAD       ( "of-200-0201.8",   0x0000000, 0x200000, CRC(bba63025) SHA1(daec5285469ee953f6f838fe3cb3903524e9ac39) )
	ROM_LOAD       ( "of-201-0202.9",   0x0200000, 0x200000, CRC(4ffd9ddc) SHA1(62bc8c0ed2efab407fc2956c514c3e732bcc47ee) )
	ROM_LOAD       ( "of-202-0203.10",  0x0400000, 0x200000, CRC(fbcc5363) SHA1(9eff48c29d5c887d39e4db442c6ee51ec879521e) )
	ROM_LOAD       ( "of-203-0204.11",  0x0600000, 0x200000, CRC(8e818ce9) SHA1(bc37d35247edfc563400cd67459d455b1fea6eab) )
	ROM_LOAD       ( "of-204-0205.12",  0x0800000, 0x200000, CRC(70c4a76b) SHA1(01b17bda156f2e6f480bdc976927c8bba47c1186) )
	ROM_LOAD       ( "of-205-0206.13",  0x0a00000, 0x200000, CRC(80c667bb) SHA1(7edf33c713c8448ff73fa84b9f7684dd4d46eed1) )
	ROM_LOAD       ( "of-206-0207.14",  0x0c00000, 0x200000, CRC(c2028c97) SHA1(ac3b73ff34f84015432ceb22cf9c57ab0ff07a70) )
	ROM_LOAD       ( "of-207-0208.15",  0x0e00000, 0x200000, CRC(b1f30c61) SHA1(2ae010c10b7a2ae09df904f7ea81425e80389622) )
	ROM_LOAD       ( "of-208-0209.28",  0x1000000, 0x200000, CRC(a8f29545) SHA1(5d018147aa71207f679909343104deaa0f08fd9d) )
	ROM_LOAD16_BYTE( "of-209e-0210.16", 0x1200000, 0x100000, CRC(93018468) SHA1(d156f408a78fbd736048ce33e44c0b1e10403b0e) )
	ROM_LOAD16_BYTE( "of-2090-2011.17", 0x1200001, 0x100000, CRC(3fb226a1) SHA1(efba54f82fb9914559faad5fba92aa108ec039d5) )
	ROM_LOAD16_BYTE( "of-210e-0212.18", 0x1400000, 0x100000, CRC(80f3fa1b) SHA1(ca0e84cb47228ef5ac3b94238a33c3ebc3c2f528) )
	ROM_LOAD16_BYTE( "of-2100-0213.19", 0x1400001, 0x100000, CRC(8ca3a3d6) SHA1(b6f3876f987ce6828bfa26ca492ff6ca2d282d80) )
	ROM_LOAD16_BYTE( "of-211e-0214.20", 0x1600000, 0x100000, CRC(8d3d96f7) SHA1(0a7c459f02938f86d53979498647c73837eb9e51) )
	ROM_LOAD16_BYTE( "of-2110-0215.21", 0x1600001, 0x100000, CRC(78268230) SHA1(63fbf88551f6fde833222ae6a4382891e1bf5b39) )
	ROM_LOAD16_BYTE( "of-212e-0216.22", 0x1800000, 0x100000, CRC(5a013d99) SHA1(c4af944c8f0b33a93b4bb083e32e2901c5607a39) )
	ROM_LOAD16_BYTE( "of-2120-0217.23", 0x1800001, 0x100000, CRC(84ed25bd) SHA1(ddff811d326586eb7353230e74db37867af075eb) )
	ROM_LOAD16_BYTE( "of-213e-0218.24", 0x1a00000, 0x100000, CRC(861bc5b1) SHA1(a85936781a56b5406bee2e4f36fadcb5b9f43b05) )
	ROM_LOAD16_BYTE( "of-2130-0219.25", 0x1a00001, 0x100000, CRC(a79b8119) SHA1(62e3fb28fd3a538a8191a51242dbed7e88c62a54) )
	ROM_LOAD16_BYTE( "of-214e-0220.26", 0x1c00000, 0x100000, CRC(43c622de) SHA1(73efe57233f056127e2d34590c624f39d1c0ab79) )
	ROM_LOAD16_BYTE( "of-2140-0221.27", 0x1c00001, 0x100000, CRC(d10bf03c) SHA1(a81d6b7df7382fc8d50614c1332611e0c202b805) )

	ROM_REGION( 0x100000, "view2_0", 0 )
	ROM_LOAD( "of-300-0225.51",    0x000000, 0x100000, CRC(fbc3c08a) SHA1(0ba52b381e7a10fb1513244b394438b440950af3) )

	ROM_REGION( 0x100000, "view2_1", 0 )
	ROM_LOAD( "of-301-0226.55",    0x000000, 0x100000, CRC(fcf215de) SHA1(83015f10e62b917efd6e3edfbd45fb8f9b35db2b) )

	ROM_REGION( 0x100000, "oki1", 0 )
	ROM_LOAD( "of-101-f-0223.101", 0x000000, 0x100000, CRC(295f3c93) SHA1(558698f1d04b23dd2a73e2eae5ecce598defb228) )

	ROM_REGION( 0x100000, "oki2", 0 )
	ROM_LOAD( "of-100-0222.99",    0x000000, 0x100000, CRC(42b12269) SHA1(f9d9c42057e176710f09e8db0bfcbf603c15ca11) )
ROM_END

/*    YEAR  NAME           PARENT    MACHINE     INPUT     INIT            MONITOR COMPANY         FULLNAME FLAGS */
//Blood Warrior
GAME( 1994, bloodwars01,   bloodwar,        bloodwar, bloodwar,  kaneko16_gtmr_state,     init_gtmr,     ROT0,  "DDJ", "Blood Warrior (Easy Move)", MACHINE_SUPPORTS_SAVE )
//Shogun Warriors
GAME( 2017, shogwarrs01,   shogwarr,        shogwarr, shogwarr,  kaneko16_shogwarr_state, init_shogwarr, ROT0,  "hack", "Shogun Warriors (Simplified 2017-02-28)", MACHINE_NO_COCKTAIL | MACHINE_SUPPORTS_SAVE )
