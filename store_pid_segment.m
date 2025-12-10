function store_pid_segment(best_PID,current_seg)
% Stores segment-wise best PID into base workspace
%
% best_PID = [3x3] → [Kp Ki Kd]
% current_seg = segment index

try
    best_PID_segments = evalin('base','best_PID_segments');
catch
    best_PID_segments = {};
end

% ensure cell exists
if isempty(best_PID_segments)
    best_PID_segments = {};
end

% expand cell if needed
if length(best_PID_segments) < current_seg
    best_PID_segments{current_seg} = [];
end

% store PID
best_PID_segments{current_seg} = best_PID;

% push to workspace
assignin('base','best_PID_segments',best_PID_segments);

end