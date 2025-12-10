% ================================
% TRAJECTORY GENERATION (SEGMENTED)
% ================================

% Maximum velocity of each direction
pos_dot = [0.2 0.15 0.12];

% Sampling time of simulink model
sampling_time = 0.001;

% Number of Cartesian points
num_points = size(pos, 1);

% Pre-allocate cell array to hold all trajectory segments
all_segments = cell(num_points, 1);

% Store starting point
starting_point = pos(1,:);

% ================================
% GENERATE SEGMENTS
% ================================
for i = 1:num_points
    
    pos_current = pos(i,:);
    
    % Determine next point (loop back at end)
    if i < num_points
        pos_next = pos(i+1,:);
    else
        pos_next = pos(1,:);
    end
    
    % Distance in each axis
    delta = abs(pos_next - pos_current);
    
    % Time required per axis at max velocity
    time = delta ./ pos_dot;
    max_time = max(time);
    
    % Prevent division by zero
    if max_time > 0
        pos_dot_modified = delta / max_time;
    else
        pos_dot_modified = zeros(1, length(delta));
    end
    
    % Step size per sample
    step_size = pos_dot_modified * sampling_time;
    
    % Generate trajectory points
    traj = LinearTrajectory(pos_current, pos_next, step_size);
    
    % Include starting point
    segment_traj = cat(1, pos_current, traj);
    
    % Store segment
    all_segments{i} = segment_traj;
end

% ================================
% COMBINE ALL SEGMENTS
% ================================
traj_pos = cell2mat(all_segments);

% ================================
% SEGMENT LENGTH INFO
% ================================
num_segments = length(all_segments);

segment_lengths = zeros(num_segments, 1);
for i = 1:num_segments
    segment_lengths(i) = size(all_segments{i}, 1);
end

% Active segment index for Simulink
active_segment = 1;