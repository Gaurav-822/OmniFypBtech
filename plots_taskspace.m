%% ----- Dynamic Trajectory Plot 1 -----

figure(2); clf; hold on;

% Auto-select valid range
n1 = size(pos_actual,1);

plot(pos_actual(:,2), pos_actual(:,1), 'b');    % actual trajectory

% Plot all waypoint points dynamically
plot(pos(:,2), pos(:,1), 'or', 'LineWidth', 2);

hold off;
title('Actual Trajectory with Waypoints');
xlabel('Y'); ylabel('X'); grid on;


%% ----- Dynamic Trajectory Plot 2 -----

figure(3); clf; hold on;

% dynamic range (full available data)
n2 = min(size(pos_actual,1), size(traj_pos,1));
% Plot all waypoint points dynamically
plot(pos(:,2), pos(:,1), 'or', 'LineWidth', 2);

% plot actual vs generated (aligned in length)
plot(pos_actual(1:n2,2), pos_actual(1:n2,1), 'r');
plot(traj_pos(1:n2,2), traj_pos(1:n2,1), 'b');

hold off;
title('Actual vs Generated Trajectory');
xlabel('Y'); ylabel('X'); grid on;
legend('Actual','Generated');
