% ================================
% NON-UNIFORM TRAJECTORY GENERATOR
% (dense ends, uniform middle)
% ================================

pos_dot = [0.2 0.15 0.12];
sampling_time = 0.001;

nonuniform_alpha = 2;

clear traj;
traj_pos = [];

starting_point = pos(1,:);

for i = 1:size(pos,1)

    pos_current = pos(i,:);
    
    if i < size(pos,1)
        pos_next = pos(i+1,:);
    else
        pos_next = pos(1,:);
    end
    
    delta = abs(pos_next - pos_current);
    time = delta ./ pos_dot;
    max_time = max(time);

    N = max(2, ceil(max_time / sampling_time));

    % ===== Non-uniform: dense ends, uniform middle =====
    t = linspace(0,1,N)';

    if nonuniform_alpha == 0
        s = t;
    else
        a = 0.2;  % 20% segment at each end

        s = zeros(size(t));

        % start dense
        idx1 = t <= a;
        u1 = t(idx1)/a;
        s(idx1) = a * (u1.^nonuniform_alpha);

        % middle uniform
        idx2 = t > a & t < (1-a);
        s(idx2) = t(idx2);

        % end dense
        idx3 = t >= (1-a);
        u3 = (t(idx3)-(1-a))/a;
        s(idx3) = (1-a) + a*(1 - (1-u3).^nonuniform_alpha);
    end

    traj = pos_current + (pos_next - pos_current).*s;
    traj_pos = cat(1, traj_pos, traj);

end

traj_pos = cat(1, pos(1,:), traj_pos);