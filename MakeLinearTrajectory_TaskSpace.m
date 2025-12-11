% NON UNIFORM TRAJECTORY GENERATOR
% smooth dynamic speed profile (slow ends, fast middle)
% zone = 1 only at waypoints

pos_dot = [0.2 0.15 0.12];
sampling_time = 0.001;

slow_factor = 0.4;   % speed at ends (0–1)
shape_power = 2;     % >1 sharper mid-speed peak

traj_pos = [];
traj_zone = [];

for i = 1:size(pos,1)

    pos_current = pos(i,:);
    if i < size(pos,1)
        pos_next = pos(i+1,:);
    else
        pos_next = pos(1,:);
    end

    delta_vec = pos_next - pos_current;
    delta = abs(delta_vec);

    % -------- estimate segment time using avg speed --------
    avg_speed_factor = slow_factor + (1-slow_factor)*0.5;
    effective_pos_dot = pos_dot * avg_speed_factor;

    time = delta ./ effective_pos_dot;
    max_time = max(time);

    N = max(2, ceil(max_time / sampling_time));
    t = linspace(0,1,N)';

    % -------- smooth bell velocity profile --------
    bell = (sin(pi*t)).^shape_power;     % 0→1→0 smooth
    v = slow_factor + (1-slow_factor)*bell;

    % -------- integrate velocity to get position scaling --------
    s = cumtrapz(t, v);
    s = s / s(end);   % normalize 0→1

    traj = pos_current + delta_vec .* s;

    % -------- zone --------
    zone = zeros(N,1);
    zone(1) = 1;

    traj_pos = [traj_pos; traj];
    traj_zone = [traj_zone; zone];

end

% add starting waypoint
traj_pos = [pos(1,:); traj_pos];
traj_zone = [1; traj_zone];