%Maximum velocity of each direction
pos_dot = [0.2 0.15 0.12];

%Sampling time of simulink model
sampling_time = .001;

%Define varaibles
clear traj;
traj_pos = [];

% Store the starting point in workspace
starting_point = pos(1,:);

%Make pos_current the first value in the array and pos_next the second value
%Increment indices for both
%When pos_current is the last entry in the array, make pos_next the first 
for i =1:size(pos,1)
    pos_current = pos(i,:);
    if i < size(pos,1)
        pos_next = pos(i+1,:);
    else
        pos_next = pos(1,:);
    end
    
    %determine the direction that will take the longest to finish its path
    %and use that speed of that direction to scale the speed of the rest
    %so that the overall path is linear
    delta = abs(pos_next-pos_current);
    time = delta./pos_dot;
    max_time = max(time);
    pos_dot_modified = delta/max_time;
    step_size = pos_dot_modified*sampling_time;
   
    %Call LinearTrajectory with pos_current,pos_next and step_size to get
    %the trajectory between these two points.
    traj= LinearTrajectory(pos_current, pos_next, step_size);
    traj_pos = cat(1,traj_pos,traj);
end

% The first entry of traj_pos is the the first entry in pos (the first point)
traj_pos = cat(1,pos(1,:),traj_pos);
