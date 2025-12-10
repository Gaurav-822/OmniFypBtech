  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Teach_Pendant_Task_Space_P)
    ;%
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.starting_point
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.traj_pos
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_P.BiasRemoval_end_time
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6003;
	
	  ;% Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6004;
	
	  ;% Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_inpu_h
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6005;
	
	  ;% Teach_Pendant_Task_Space_P.BiasRemoval_start_time
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6006;
	
	  ;% Teach_Pendant_Task_Space_P.BiasRemoval_switch_id
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6007;
	
	  ;% Teach_Pendant_Task_Space_P.unity_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 6008;
	
	  ;% Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 6009;
	
	  ;% Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 6010;
	
	  ;% Teach_Pendant_Task_Space_P.zero_Y0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 6011;
	
	  ;% Teach_Pendant_Task_Space_P.Vbiased_Y0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 6012;
	
	  ;% Teach_Pendant_Task_Space_P.Vunbiased_Y0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 6013;
	
	  ;% Teach_Pendant_Task_Space_P.Stepstart_time_Y0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 6014;
	
	  ;% Teach_Pendant_Task_Space_P.Stepstart_time_YFinal
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 6015;
	
	  ;% Teach_Pendant_Task_Space_P.Stepend_time_Y0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 6016;
	
	  ;% Teach_Pendant_Task_Space_P.Stepend_time_YFinal
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 6017;
	
	  ;% Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 6018;
	
	  ;% Teach_Pendant_Task_Space_P.firstpoint_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 6019;
	
	  ;% Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_g
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 6022;
	
	  ;% Teach_Pendant_Task_Space_P.EncoderOffsets_Bias
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 6023;
	
	  ;% Teach_Pendant_Task_Space_P.Bias1_Bias
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 6029;
	
	  ;% Teach_Pendant_Task_Space_P.Encoder_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 6032;
	
	  ;% Teach_Pendant_Task_Space_P.GearRatio_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 6033;
	
	  ;% Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConven
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 6036;
	
	  ;% Teach_Pendant_Task_Space_P.JointOffsets_Bias
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 6039;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtUnitDelay1_InitialConditio
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 6042;
	
	  ;% Teach_Pendant_Task_Space_P.speed_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 6043;
	
	  ;% Teach_Pendant_Task_Space_P.Constant2_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 6044;
	
	  ;% Teach_Pendant_Task_Space_P.Constant3_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 6045;
	
	  ;% Teach_Pendant_Task_Space_P.Constant2_Value_h
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 6046;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation1_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 6047;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation1_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 6050;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation2_UpperSat
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 6053;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation2_LowerSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 6056;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation_UpperSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 6059;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation_LowerSat
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 6062;
	
	  ;% Teach_Pendant_Task_Space_P.Integrator_IC
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 6065;
	
	  ;% Teach_Pendant_Task_Space_P.Integrator2_IC
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 6066;
	
	  ;% Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConv_g
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 6067;
	
	  ;% Teach_Pendant_Task_Space_P.Constant_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 6070;
	
	  ;% Teach_Pendant_Task_Space_P.x0_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 6071;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtConstant_Value
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Teach_Pendant_Task_Space_B)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_B.UnitDelay
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_B.Phantom_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_B.JointOffsets
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 9;
	
	  ;% Teach_Pendant_Task_Space_B.Switch
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 12;
	
	  ;% Teach_Pendant_Task_Space_B.Subtract
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% Teach_Pendant_Task_Space_B.Saturation1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 18;
	
	  ;% Teach_Pendant_Task_Space_B.Saturation2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 21;
	
	  ;% Teach_Pendant_Task_Space_B.Saturation
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 24;
	
	  ;% Teach_Pendant_Task_Space_B.Sum1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 27;
	
	  ;% Teach_Pendant_Task_Space_B.Product1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 30;
	
	  ;% Teach_Pendant_Task_Space_B.Product1_g
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 33;
	
	  ;% Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 36;
	
	  ;% Teach_Pendant_Task_Space_B.x0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 39;
	
	  ;% Teach_Pendant_Task_Space_B.Product
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 40;
	
	  ;% Teach_Pendant_Task_Space_B.Ki
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 43;
	
	  ;% Teach_Pendant_Task_Space_B.Kd
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 46;
	
	  ;% Teach_Pendant_Task_Space_B.best_PID
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 49;
	
	  ;% Teach_Pendant_Task_Space_B.worst_PID
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 58;
	
	  ;% Teach_Pendant_Task_Space_B.q
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 67;
	
	  ;% Teach_Pendant_Task_Space_B.inter
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 70;
	
	  ;% Teach_Pendant_Task_Space_B.div
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 73;
	
	  ;% Teach_Pendant_Task_Space_B.out
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 76;
	
	  ;% Teach_Pendant_Task_Space_B.total_cost
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 85;
	
	  ;% Teach_Pendant_Task_Space_B.pos
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 86;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_B.Phantom_o1
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_B.Phantom_o3
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_B.reached
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Teach_Pendant_Task_Space_DW)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_b
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% Teach_Pendant_Task_Space_DW.particles
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% Teach_Pendant_Task_Space_DW.velocities
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 133;
	
	  ;% Teach_Pendant_Task_Space_DW.pbest
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 253;
	
	  ;% Teach_Pendant_Task_Space_DW.pbest_cost
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 373;
	
	  ;% Teach_Pendant_Task_Space_DW.gbest
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 393;
	
	  ;% Teach_Pendant_Task_Space_DW.gbest_cost
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 399;
	
	  ;% Teach_Pendant_Task_Space_DW.current_particle
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 400;
	
	  ;% Teach_Pendant_Task_Space_DW.eval_count
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 401;
	
	  ;% Teach_Pendant_Task_Space_DW.idx
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 402;
	
	  ;% Teach_Pendant_Task_Space_DW.N
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 403;
	
	  ;% Teach_Pendant_Task_Space_DW.cost_sum
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 404;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.Phantom_Phantom
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.method
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.state
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_DW.state_k
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Teach_Pendant_Task_Space_DW.state_j
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCase_ActiveSubsystem
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Teach_Pendant_Task_Space_DW.EnabledMovingAverage_SubsysRanB
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.initialized_not_empty
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.in_zone_prev
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_DW.state_not_empty
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Teach_Pendant_Task_Space_DW.Traject_MODE
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4200602517;
  targMap.checksum1 = 3286302902;
  targMap.checksum2 = 2135106923;
  targMap.checksum3 = 3174512592;

