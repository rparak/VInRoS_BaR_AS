MODULE Module1
    ! ## =========================================================================== ## 
    ! MIT License
    ! Copyright (c) 2021 Roman Parak
    ! Permission is hereby granted, free of charge, to any person obtaining a copy
    ! of this software and associated documentation files (the "Software"), to deal
    ! in the Software without restriction, including without limitation the rights
    ! to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    ! copies of the Software, and to permit persons to whom the Software is
    ! furnished to do so, subject to the following conditions:
    ! The above copyright notice and this permission notice shall be included in all
    ! copies or substantial portions of the Software.
    ! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    ! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    ! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    ! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    ! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    ! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    ! SOFTWARE.
    ! ## =========================================================================== ## 
    ! Author   : Roman Parak
    ! Email    : Roman.Parak@outlook.com
    ! Github   : https://github.com/rparak
    ! File Name: T_ROB_PLC_PROFINET_CPR/Module1.mod
    ! ## =========================================================================== ## 
    
    
    ! Description: !
    !   Joint Position Data (Q0 - Q5): sign (+-) !
    RECORD robot_dataC_joint_str
        num Q0_Sign;
        num Q1_Sign;
        num Q2_Sign;
        num Q3_Sign;
        num Q4_Sign;
        num Q5_Sign;
        num Q6_Sign;
    ENDRECORD
    
    ! Description: !
    !   The main structure of data collection on the current position of the robot with sign (+-) !
    RECORD robot_dataC_main_str
        robot_dataC_joint_str joint;              ! Joint Position Data (Q0 - Q5): sign (+-)
        jointtarget JOINT_CURRENT_DATA;           ! Joint Position Data
    ENDRECORD
    
    ! Call Main Structure
    !   Note: VAR robot_dataC_main_str r_data_collection := [[0,0,0,0,0,0],[[0,0,0,0,0,0],[0,0,0,0,0,0]]];
    VAR robot_dataC_main_str r_data_collection;
    
    ! Characteristics of a robotic tool (end-effector / gripper)
    !   Note: Current Data (T_ROB_PLC_PROFINET_CPR)
    !PERS tooldata robTool_CPR := [TRUE,[[0,0,0],[1,0,0,0]],[0.001,[0,0,0.001],[1,0,0,0],0,0,0]];
    PERS tooldata robTool_CPR;
    
    ! Variable for rounded (Joint, Cartesian) data
    VAR num NUM_OF_ROUNDED_PLACES := 2;
    
    ! Mathematical Constant PI
    VAR num M_PI := 3.14159;
    
    ! Accuracy factor for value conversion
    VAR num accuracy_factor := 100;

    ! Description:                   !
    !   Program Main Cycle:          !
    !       Type        : Semistatic !
    !       TrustLeve   : No Safety  !
    !       Motion Task : N/A        !
    PROC Main()
        ! Description:                                                       !
        !   Read the current angles of the robot axes (Joint).               ! 
        !       Note: The resulting data is rounded with the Round function  !
        
        r_data_collection.JOINT_CURRENT_DATA := CJointT();
        
        ! Joint (Q0 .. Q5) -> Q0 Parameter (Joint Number 0)
        r_data_collection.joint.Q0_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.robax.rax_1 \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q0_SIGN_PROFINET_OUT, r_data_collection.joint.Q0_Sign;
        IF r_data_collection.joint.Q0_Sign = 0 THEN
            SetGO Q0_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.robax.rax_1 * accuracy_factor)) \Dec:=0);
        ELSE
            SetGO Q0_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.robax.rax_1 * accuracy_factor) \Dec:=0);
        ENDIF
        !   Q0 Parameter (External)
        r_data_collection.joint.Q6_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.extax.eax_a \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q6_SIGN_PROFINET_OUT, r_data_collection.joint.Q6_Sign;
        IF r_data_collection.JOINT_CURRENT_DATA.extax.eax_a <> 9E+09 THEN
            IF r_data_collection.joint.Q6_Sign = 0 THEN
                SetGO Q6_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.extax.eax_a * accuracy_factor)) \Dec:=0);
            ELSE
                SetGO Q6_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.extax.eax_a * accuracy_factor) \Dec:=0);
            ENDIF
        ENDIF
        
        ! Joint (Q0 .. Q5) -> Q1 Parameter (Joint Number 1)
        r_data_collection.joint.Q1_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.robax.rax_2 \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q1_SIGN_PROFINET_OUT, r_data_collection.joint.Q1_Sign;
        IF r_data_collection.joint.Q1_Sign = 0 THEN
            SetGO Q1_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.robax.rax_2 * accuracy_factor)) \Dec:=0);
        ELSE
            SetGO Q1_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.robax.rax_2 * accuracy_factor) \Dec:=0);
        ENDIF
        
        ! Joint (Q0 .. Q5) -> Q2 Parameter (Joint Number 2)
        r_data_collection.joint.Q2_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.robax.rax_3 \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q2_SIGN_PROFINET_OUT, r_data_collection.joint.Q2_Sign;
        IF r_data_collection.joint.Q2_Sign = 0 THEN
            SetGO Q2_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.robax.rax_3 * accuracy_factor)) \Dec:=0);
        ELSE
            SetGO Q2_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.robax.rax_3 * accuracy_factor) \Dec:=0);
        ENDIF
        
        ! Joint (Q0 .. Q5) -> Q3 Parameter (Joint Number 3)
        r_data_collection.joint.Q3_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.robax.rax_4 \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q3_SIGN_PROFINET_OUT, r_data_collection.joint.Q3_Sign;
        IF r_data_collection.joint.Q3_Sign = 0 THEN
            SetGO Q3_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.robax.rax_4 * accuracy_factor)) \Dec:=0);
        ELSE
            SetGO Q3_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.robax.rax_4 * accuracy_factor) \Dec:=0);
        ENDIF
        
        ! Joint (Q0 .. Q5) -> Q4 Parameter (Joint Number 4)
        r_data_collection.joint.Q4_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.robax.rax_5 \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q4_SIGN_PROFINET_OUT, r_data_collection.joint.Q4_Sign;
        IF r_data_collection.joint.Q4_Sign = 0 THEN
            SetGO Q4_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.robax.rax_5 * accuracy_factor)) \Dec:=0);
        ELSE
            SetGO Q4_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.robax.rax_5 * accuracy_factor) \Dec:=0);
        ENDIF
        
        ! Joint (Q0 .. Q5) -> Q5 Parameter (Joint Number 5)
        r_data_collection.joint.Q5_Sign := sign(Round(r_data_collection.JOINT_CURRENT_DATA.robax.rax_6 \Dec:=NUM_OF_ROUNDED_PLACES));
        SetDo Q5_SIGN_PROFINET_OUT, r_data_collection.joint.Q5_Sign;
        IF r_data_collection.joint.Q5_Sign = 0 THEN
            SetGO Q5_PROFINET_OUT, Round(((-1) * (r_data_collection.JOINT_CURRENT_DATA.robax.rax_6 * accuracy_factor)) \Dec:=0);
        ELSE
            SetGO Q5_PROFINET_OUT, Round((r_data_collection.JOINT_CURRENT_DATA.robax.rax_6 * accuracy_factor) \Dec:=0);
        ENDIF
    ENDPROC
    
    
    FUNC num sign(num value)
        ! Description:                                                       !
        !   A simple mathematical function that extracts a real number sign. !
        !                                                                    !
        ! IN:                                                                !
        ! [1] value [num]: Real number.                                      !
        ! OUT:                                                               !
        ! [1] return [num]: Sign (1: Positive {+}, 0: Negative {-}).         !
        
        IF value >= 0 THEN
           RETURN 1;
        ELSE
           RETURN 0;
        ENDIF
    ENDFUNC
    
    FUNC num DegToRad(num value)
        ! Description:                                       !
        !   Conversion function between degrees and radians. !
        !                                                    !
        ! IN:                                                !
        ! [1] value [num]: Real number (Degree).             !
        ! OUT:                                               !
        ! [1] return [num]: Radian.                          !
        
        RETURN ((value) * M_PI / 180.0);
    ENDFUNC
    
    PROC ER_Reset_Parameters_CPR()
        ! Description:                                                   !
        !   Event routine function (non-parametric) for parameter reset. !
        !       Note: Configuration / Controller / Event Routine         !
        
        ! Main Structure for data collection
        r_data_collection := [[0,0,0,0,0,0,0],[[0,0,0,0,0,0],[0,0,0,0,0,0]]];
        
        ! Characteristics of a robotic tool (end-effector / gripper)
        robTool_CPR := [TRUE,[[0,0,0],[1,0,0,0]],[0.001,[0,0,0.001],[1,0,0,0],0,0,0]];
	ENDPROC
ENDMODULE