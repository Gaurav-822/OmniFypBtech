  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.segment_lengths
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.starting_point
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_P.TrajectoryJoint1_OutValues
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Teach_Pendant_Task_Space_P.TrajectoryJoint2_OutValues
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 2102;
	
	  ;% Teach_Pendant_Task_Space_P.TrajectoryJoint3_OutValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4198;
	
	  ;% Teach_Pendant_Task_Space_P.BiasRemoval_end_time
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6294;
	
	  ;% Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_input_
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6295;
	
	  ;% Teach_Pendant_Task_Space_P.SecondOrderLowPassFilter_inpu_h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 6296;
	
	  ;% Teach_Pendant_Task_Space_P.BiasRemoval_start_time
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 6297;
	
	  ;% Teach_Pendant_Task_Space_P.BiasRemoval_switch_id
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 6298;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.LimitedCounter_uplimit
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.LimitedCounter_uplimit_p
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_P.LimitedCounter_uplimit_k
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.unity_Value
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_P.Sumk1n1xk_InitialCondition
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Teach_Pendant_Task_Space_P.zero_Y0
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_P.Vbiased_Y0
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Teach_Pendant_Task_Space_P.Vunbiased_Y0
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Teach_Pendant_Task_Space_P.Stepstart_time_Y0
	  section.data(7).logicalSrcIdx = 19;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Teach_Pendant_Task_Space_P.Stepstart_time_YFinal
	  section.data(8).logicalSrcIdx = 20;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Teach_Pendant_Task_Space_P.Stepend_time_Y0
	  section.data(9).logicalSrcIdx = 21;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Teach_Pendant_Task_Space_P.Stepend_time_YFinal
	  section.data(10).logicalSrcIdx = 22;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_j
	  section.data(11).logicalSrcIdx = 23;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Teach_Pendant_Task_Space_P.firstpoint_Value
	  section.data(12).logicalSrcIdx = 24;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Teach_Pendant_Task_Space_P.UnitDelay_InitialCondition_g
	  section.data(13).logicalSrcIdx = 25;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Teach_Pendant_Task_Space_P.EncoderOffsets_Bias
	  section.data(14).logicalSrcIdx = 26;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Teach_Pendant_Task_Space_P.Bias1_Bias
	  section.data(15).logicalSrcIdx = 27;
	  section.data(15).dtTransOffset = 21;
	
	  ;% Teach_Pendant_Task_Space_P.Encoder_Gain
	  section.data(16).logicalSrcIdx = 28;
	  section.data(16).dtTransOffset = 24;
	
	  ;% Teach_Pendant_Task_Space_P.GearRatio_Gain
	  section.data(17).logicalSrcIdx = 29;
	  section.data(17).dtTransOffset = 25;
	
	  ;% Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConven
	  section.data(18).logicalSrcIdx = 30;
	  section.data(18).dtTransOffset = 28;
	
	  ;% Teach_Pendant_Task_Space_P.JointOffsets_Bias
	  section.data(19).logicalSrcIdx = 31;
	  section.data(19).dtTransOffset = 31;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtUnitDelay1_InitialConditio
	  section.data(20).logicalSrcIdx = 32;
	  section.data(20).dtTransOffset = 34;
	
	  ;% Teach_Pendant_Task_Space_P.speed_Value
	  section.data(21).logicalSrcIdx = 33;
	  section.data(21).dtTransOffset = 35;
	
	  ;% Teach_Pendant_Task_Space_P.Constant2_Value
	  section.data(22).logicalSrcIdx = 34;
	  section.data(22).dtTransOffset = 36;
	
	  ;% Teach_Pendant_Task_Space_P.Constant2_Value_h
	  section.data(23).logicalSrcIdx = 35;
	  section.data(23).dtTransOffset = 37;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation1_UpperSat
	  section.data(24).logicalSrcIdx = 36;
	  section.data(24).dtTransOffset = 38;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation1_LowerSat
	  section.data(25).logicalSrcIdx = 37;
	  section.data(25).dtTransOffset = 41;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation2_UpperSat
	  section.data(26).logicalSrcIdx = 38;
	  section.data(26).dtTransOffset = 44;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation2_LowerSat
	  section.data(27).logicalSrcIdx = 39;
	  section.data(27).dtTransOffset = 47;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation_UpperSat
	  section.data(28).logicalSrcIdx = 40;
	  section.data(28).dtTransOffset = 50;
	
	  ;% Teach_Pendant_Task_Space_P.Saturation_LowerSat
	  section.data(29).logicalSrcIdx = 41;
	  section.data(29).dtTransOffset = 53;
	
	  ;% Teach_Pendant_Task_Space_P.Integrator_IC
	  section.data(30).logicalSrcIdx = 42;
	  section.data(30).dtTransOffset = 56;
	
	  ;% Teach_Pendant_Task_Space_P.Integrator2_IC
	  section.data(31).logicalSrcIdx = 43;
	  section.data(31).dtTransOffset = 57;
	
	  ;% Teach_Pendant_Task_Space_P.ConverttoPositiveRotationConv_g
	  section.data(32).logicalSrcIdx = 44;
	  section.data(32).dtTransOffset = 58;
	
	  ;% Teach_Pendant_Task_Space_P.Constant_Value
	  section.data(33).logicalSrcIdx = 45;
	  section.data(33).dtTransOffset = 61;
	
	  ;% Teach_Pendant_Task_Space_P.x0_Value
	  section.data(34).logicalSrcIdx = 46;
	  section.data(34).dtTransOffset = 62;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.Constant4_Value
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.Constant_Value_h
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.Constant_Value_f
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_P.Constant_Value_m
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_P.Output_InitialCondition
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtConstant_Value_m
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Teach_Pendant_Task_Space_P.Output_InitialCondition_p
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtConstant_Value_c
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Teach_Pendant_Task_Space_P.Output_InitialCondition_b
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_P.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_P.FixPtConstant_Value_l
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Teach_Pendant_Task_Space_B)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_B.Add
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_B.UnitDelay
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_B.Phantom_o2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Teach_Pendant_Task_Space_B.JointOffsets
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% Teach_Pendant_Task_Space_B.Switch
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 13;
	
	  ;% Teach_Pendant_Task_Space_B.Subtract
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 16;
	
	  ;% Teach_Pendant_Task_Space_B.Saturation1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 19;
	
	  ;% Teach_Pendant_Task_Space_B.Saturation2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 22;
	
	  ;% Teach_Pendant_Task_Space_B.Saturation
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 25;
	
	  ;% Teach_Pendant_Task_Space_B.Sum1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 28;
	
	  ;% Teach_Pendant_Task_Space_B.Product1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 31;
	
	  ;% Teach_Pendant_Task_Space_B.Product1_g
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 34;
	
	  ;% Teach_Pendant_Task_Space_B.ConverttoPositiveRotationConven
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 37;
	
	  ;% Teach_Pendant_Task_Space_B.x0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 40;
	
	  ;% Teach_Pendant_Task_Space_B.Product
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 41;
	
	  ;% Teach_Pendant_Task_Space_B.best_Kp
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 44;
	
	  ;% Teach_Pendant_Task_Space_B.best_Ki
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 47;
	
	  ;% Teach_Pendant_Task_Space_B.best_Kd
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 50;
	
	  ;% Teach_Pendant_Task_Space_B.current_seg
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 53;
	
	  ;% Teach_Pendant_Task_Space_B.Out
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 54;
	
	  ;% Teach_Pendant_Task_Space_B.Out_i
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 55;
	
	  ;% Teach_Pendant_Task_Space_B.Out_p
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 56;
	
	  ;% Teach_Pendant_Task_Space_B.inter
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 57;
	
	  ;% Teach_Pendant_Task_Space_B.div
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 60;
	
	  ;% Teach_Pendant_Task_Space_B.Kp_p
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 63;
	
	  ;% Teach_Pendant_Task_Space_B.Ki_g
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 66;
	
	  ;% Teach_Pendant_Task_Space_B.Kd_f
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 69;
	
	  ;% Teach_Pendant_Task_Space_B.current_seg_b
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 72;
	
	  ;% Teach_Pendant_Task_Space_B.total_cost
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 73;
	
	  ;% Teach_Pendant_Task_Space_B.pos
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 74;
	
	  ;% Teach_Pendant_Task_Space_B.out
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_B.Phantom_o1
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_B.Phantom_o3
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 9;
    sectIdxOffset = 2;
    
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
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_DW.FixPtUnitDelay1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Teach_Pendant_Task_Space_DW.UnitDelay_DSTATE_h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Teach_Pendant_Task_Space_DW.Sumk1n1xk_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Teach_Pendant_Task_Space_DW.particles
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Teach_Pendant_Task_Space_DW.velocities
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 1211;
	
	  ;% Teach_Pendant_Task_Space_DW.pbest
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 2411;
	
	  ;% Teach_Pendant_Task_Space_DW.pbest_cost
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 3611;
	
	  ;% Teach_Pendant_Task_Space_DW.gbest
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 3811;
	
	  ;% Teach_Pendant_Task_Space_DW.gbest_cost
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 3871;
	
	  ;% Teach_Pendant_Task_Space_DW.current_particle
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 3881;
	
	  ;% Teach_Pendant_Task_Space_DW.eval_count
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 3891;
	
	  ;% Teach_Pendant_Task_Space_DW.last_seg
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 3901;
	
	  ;% Teach_Pendant_Task_Space_DW.cost_accum
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 3902;
	
	  ;% Teach_Pendant_Task_Space_DW.last_seg_b
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 3912;
	
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
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.Output_DSTATE_j
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_DW.Output_DSTATE_c
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.Traject_SubsysRanBC
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCase_ActiveSubsystem
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Teach_Pendant_Task_Space_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Teach_Pendant_Task_Space_DW.EnabledMovingAverage_SubsysRanB
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Teach_Pendant_Task_Space_DW.in_zone_prev
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Teach_Pendant_Task_Space_DW.initialized_not_empty
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 10;
	
	  ;% Teach_Pendant_Task_Space_DW.state_not_empty
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 11;
	
	  ;% Teach_Pendant_Task_Space_DW.Traject_MODE
	  section.data(4).logicalSrcIdx = 37;
	  section.data(4).dtTransOffset = 12;
	
	  ;% Teach_Pendant_Task_Space_DW.EnabledMovingAverage_MODE
	  section.data(5).logicalSrcIdx = 38;
	  section.data(5).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 3312278886;
  targMap.checksum1 = 3524803694;
  targMap.checksum2 = 409222793;
  targMap.checksum3 = 3174842057;

