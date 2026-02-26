% Maximum velocity of each direction
pos_dot = [0.2/4 0.15/4 0.12/4];

% Sampling time of simulink model
sampling_time = .001;

% Define variables
num_points = size(pos, 1);

% Pre-allocate a cell array to hold all generated segments
% We use a cell array because each segment will have a different number of rows
all_segments = cell(num_points, 1); 

% Store the starting point in workspace
starting_point = pos(1,:);

for i = 1:num_points
    pos_current = pos(i,:);
    
    % Determine the next point. If at the last point, loop back to the first.
    if i < num_points
        pos_next = pos(i+1,:);
    else
        pos_next = pos(1,:);
    end
    
    % Determine the direction that will take the longest to finish its path
    delta = abs(pos_next - pos_current);
    time = delta ./ pos_dot;
    max_time = max(time);
    
    % Prevent division by zero if points happen to be identical
    if max_time > 0
        pos_dot_modified = delta / max_time;
    else
        pos_dot_modified = zeros(1, length(delta));
    end
    
    step_size = pos_dot_modified * sampling_time;
   
    % Call LinearTrajectory with pos_current, pos_next and step_size
    traj = LinearTrajectory(pos_current, pos_next, step_size);
    
    % Combine the start point and the generated trajectory
    segment_traj = cat(1, pos_current, traj);
    
    % Store this completed segment into our cell array
    all_segments{i} = segment_traj;
end

% --- SIMULINK SETUP ---
% All segments are now generated and stored in 'all_segments'.
% Define which segment Simulink should currently use (1 = A->B, 2 = B->C, 3 = C->A)
active_segment = 1; 

% Make traj_pos JUST the segment currently being worked on
%traj_pos = all_segments{active_segment};

traj_pos = cell2mat(all_segments);

% Get the number of rows (iterations) for each segment
segment_lengths = zeros(num_segments, 1);
for i = 1:num_segments
    segment_lengths(i) = size(all_segments{i}, 1);
end