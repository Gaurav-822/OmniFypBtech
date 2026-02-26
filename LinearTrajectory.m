%This function creates a linear trajectory between two points

function [trajectory] = LinearTrajectory(q_current, q_next, step_size)

% find the number of steps needed to complete the trajectory based on the
% distance to travel and the step size.
diff =abs(q_next - q_current);
num_steps = floor(diff./step_size);

%initialize variables
i = 0;
trajectory = [];
if diff(1) == 0.0477
    p = 1;
end
% create linear trajectory
for i = 1:num_steps
    if i ==1
        trajectory(i,1:3) = q_current + 2*sign(q_next-q_current).*step_size;
    else
        trajectory(i,1:3) = trajectory(i-1,1:3) + sign(q_next-q_current).*step_size;
    end
end

% the last entry in the trajectory is q_next
trajectory(i+1,1:3) = q_next;

end
