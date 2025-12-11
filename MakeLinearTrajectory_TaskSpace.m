% TRAJECTORY WITH SMOOTH TEARDROP OUTWARD LOOPS (BEZIER ENTRY/EXIT)
% straight edges + smooth bezier loop at vertex with INDEPENDENT SLOW SPEED

pos_dot = [0.2 0.15 0.12];
loop_speed = 0.2;     % <--- NEW: Set your slow speed for the overshoot loop here
sampling_time = 0.001;

overshoot = 0.2;       % loop size fraction
N_loop_min = 30;

traj_pos = [];
traj_zone = [];

num_pts = size(pos,1);

for i = 1:num_pts

    % ===== points =====
    P0 = pos(i,:);
    
    % Next point (the corner vertex we are heading towards)
    if i < num_pts
        P1 = pos(i+1,:);
    else
        P1 = pos(1,:);
    end
    
    % Point after next (needed to know the exit direction for the loop)
    if i < num_pts - 1
        P2 = pos(i+2,:);
    elseif i == num_pts - 1
        P2 = pos(1,:);
    else % i == num_pts
        P2 = pos(2,:);
    end

    d = P1 - P0;
    L = norm(d);

    % =========================
    % SMOOTH TEARDROP LOOP (BEZIER) SETUP
    % =========================
    % 1. Get normalized directions for incoming and outgoing paths
    vin  = P1 - P0;
    vout = P2 - P1;

    vin_dir  = vin / (norm(vin) + 1e-9);
    vout_dir = vout / (norm(vout) + 1e-9);

    % 2. Setup Bezier Control Points
    k = overshoot * L * 2.0; 

    B0 = P1;                   % Start loop exactly at the vertex
    B1 = P1 + k * vin_dir;     % Tangent control: push forward along incoming direction
    B2 = P1 - k * vout_dir;    % Tangent control: pull backward from outgoing direction
    B3 = P1;                   % End loop exactly at the vertex

    % =========================
    % TIMING & SAMPLES CALCULATION
    % =========================
    % LINE: Time based on standard pos_dot limits
    time_line = max(abs(d) ./ pos_dot);
    N_line = max(2, ceil(time_line / sampling_time));

    % LOOP: Estimate arc length using the control polygon
    L_poly = norm(B1 - B0) + norm(B2 - B1) + norm(B3 - B2);
    
    % Calculate samples needed to maintain the slow loop_speed
    time_loop = L_poly / loop_speed;
    N_loop = max(N_loop_min, ceil(time_loop / sampling_time));

    % =========================
    % GENERATE TRAJECTORIES
    % =========================
    % Straight Segment
    t_line = linspace(0,1,N_line)';
    line_traj = P0 + d .* t_line;

    % Teardrop Loop Segment
    t_loop = linspace(0, 1, N_loop)';
    
    loop_traj = (1-t_loop).^3 .* B0 ...
              + 3.*(1-t_loop).^2 .* t_loop .* B1 ...
              + 3.*(1-t_loop) .* t_loop.^2 .* B2 ...
              + t_loop.^3 .* B3;

    % =========================
    % COMBINE
    % =========================
    % Exclude the very last point of line_traj to prevent a duplicate data point at P1
    segment = [line_traj(1:end-1, :); loop_traj];

    zone = zeros(size(segment,1),1);
    zone(end) = 1; % Mark the endpoint of the loop

    traj_pos = [traj_pos; segment];
    traj_zone = [traj_zone; zone];

end

traj_pos = [pos(1,:); traj_pos];
traj_zone = [1; traj_zone];

% =========================
% EXTEND TRAJECTORY ZONES
% =========================
points_after = 50;  % Keeps the zone active for 50 points AFTER the endpoint
points_before = 0;  % Change this if you also want it active BEFORE the endpoint

% Find all indices where the zone is currently set to 1
zone_indices = find(traj_zone == 1);

% Expand the zone window around each endpoint
for idx = 1:length(zone_indices)
    idx_center = zone_indices(idx);
    
    % Calculate start and end indices, ensuring they don't exceed array bounds
    idx_start = max(1, idx_center - points_before);
    idx_end   = min(length(traj_zone), idx_center + points_after);
    
    traj_zone(idx_start:idx_end) = 1;
end