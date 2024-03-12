[LIT]
9
40	25	40	28	40
41	28	40	30	40
42	28	40	28	60
43	28	60	52	60
44	76	60	127	60
50	95	28	95	68
51	60	28	95	28
52	95	68	127	68
55	171	64	173	64

[TET]
12
0	23	23	30	25	4	5	TRUE
1	18	31	30	33	4	5	SAFETRUE
2	18	35	30	37	4	5	SAFEFALSE
3	10	39	25	41	4	5	COM_RESET_SF
4	18	27	30	29	4	5	SDI_ESTOP
45	120	55	127	57	4	5	TRUE
46	115	71	127	73	4	5	SAFETRUE
47	115	75	127	77	4	5	SAFETRUE
48	110	83	127	85	4	5	SM_Axis_ROB_01
49	115	63	127	65	4	5	SAFETRUE
53	115	79	127	81	4	5	SAFETRUE
54	173	63	202	65	4	3	COM_STATUS_OPERATIONAL

[FBS]
3
14	32	20	58	44	0	SF_EmergencyStop_V1_00	SF_EmergencyStop_V1_00_1
35	129	52	169	100	0	SF_oS_MOTION_Basic_BR	SF_oS_MOTION_Basic_BR_1
39	54	56	74	64	1	BOOL_TO_SAFEBOOL	

[FPT]
30
5	32	23	42	25	Activate	0	128	0	BOOL
6	32	27	44	29	S_EStopIn	0	128	0	SAFEBOOL
7	32	31	46	33	S_StartReset	0	128	0	SAFEBOOL
8	32	35	46	37	S_AutoReset	0	128	0	SAFEBOOL
9	32	39	39	41	Reset	0	128	0	BOOL
10	51	23	58	25	Ready	1	0	128	BOOL
11	46	27	58	29	S_EStopOut	1	0	128	SAFEBOOL
12	52	31	58	33	Error	1	0	128	BOOL
13	48	35	58	37	DiagCode	1	0	128	WORD
16	129	55	139	57	Activate	0	128	0	BOOL
17	129	59	146	61	S_Control_Reset	0	128	0	SAFEBOOL
18	129	63	148	65	S_Control_Activate	0	128	0	SAFEBOOL
19	129	67	145	69	S_Control_STO	0	128	0	SAFEBOOL
20	129	71	145	73	S_Control_SBC	0	128	0	SAFEBOOL
21	129	75	144	77	S_Control_SS1	0	128	0	SAFEBOOL
22	129	79	146	81	S_Control_STO1	0	128	0	SAFEBOOL
23	129	83	140	85	S_AxisID	0	128	0	SAFEINT
24	162	55	169	57	Ready	1	0	128	BOOL
25	149	59	169	61	S_Status_NotErrFunc	1	0	128	SAFEBOOL
26	148	63	169	65	S_Status_Operational	1	0	128	SAFEBOOL
27	155	67	169	69	S_Status_STO	1	0	128	SAFEBOOL
28	155	71	169	73	S_Status_SBC	1	0	128	SAFEBOOL
29	155	75	169	77	S_Status_SS1	1	0	128	SAFEBOOL
30	154	79	169	81	S_Status_STO1	1	0	128	SAFEBOOL
31	155	83	169	85	S_Status_SDC	1	0	128	SAFEBOOL
32	150	87	169	89	S_Status_EncStatus	1	0	128	SAFEBOOL
33	163	91	169	93	Error	1	0	128	BOOL
34	159	95	169	97	DiagCode	1	0	128	WORD
37	54	59	56	61		0	640	0	BOOL
38	73	59	74	61		1	0	640	SAFEBOOL

[KOT]
0

[VER]
0

