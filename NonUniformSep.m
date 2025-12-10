% ===== Current alpha you are using =====
alpha = nonuniform_alpha;

traj_pos = [];

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
    t = linspace(0,1,N)';

    % ===== SAME NON-UNIFORM + FIX =====
    if alpha == 0
        s = t;
    else
        ta = t.^alpha;
        tb = (1 - t).^alpha;
        s = ta ./ (ta + tb);

        s(1) = 0;
        s(end) = 1;
        s = max(0, min(1, s));
        s = cummax(s);
    end

    traj = pos_current + (pos_next - pos_current).*s;
    traj_pos = cat(1, traj_pos, traj);
end

traj_pos = cat(1, pos(1,:), traj_pos);

% ===== PLOT =====
figure; clf; hold on; grid on;

plot(traj_pos(:,2), traj_pos(:,1), '.b');           % sampled points
plot(pos(:,2), pos(:,1), 'or', 'LineWidth', 2);     % waypoints

axis equal;
title(['Trajectory (alpha = ', num2str(alpha), ')']);
xlabel('Y');
ylabel('X');

legend('Sampled trajectory','Waypoints');