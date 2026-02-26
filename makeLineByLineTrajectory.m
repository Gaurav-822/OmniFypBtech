% Maximum velocity of each direction
pos_dot = [0.2 0.15 0.12];

% Sampling time of simulink model
sampling_time = .001;

clear traj_segments;
traj_segments = {};

starting_points = {};
final_points = {};

numSeg = size(pos,1) - 1;   % number of line segments

for i = 1:numSeg
    
    pos_current = pos(i,:);
    pos_next = pos(i+1,:);
    
    % store segment endpoints
    starting_points{i} = pos_current;
    final_points{i}    = pos_next;
    
    % compute linear speed scaling
    delta = abs(pos_next - pos_current);
    time = delta ./ pos_dot;
    max_time = max(time);
    
    pos_dot_modified = delta / max_time;
    step_size = pos_dot_modified * sampling_time;
    
    % trajectory of THIS line only
    traj = LinearTrajectory(pos_current, pos_next, step_size);
    
    % store separately
    traj_segments{i} = traj;
    
end