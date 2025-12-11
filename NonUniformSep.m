%% ----- Dynamic Trajectory Plot (All Points) -----

figure(2); clf; hold on; axis equal;

% --- lengths ---
n_actual = size(pos_actual,1);
n_gen    = size(traj_pos,1);
n_align  = min(n_actual, n_gen);

% --- Generated trajectory (points) ---
plot(traj_pos(1:n_align,2), traj_pos(1:n_align,1), ...
    '.r', 'MarkerSize', 8);

% --- Input waypoints (pos) ---
plot(pos(:,2), pos(:,1), ...
    'ok', 'MarkerSize', 8, 'LineWidth', 2);

% --- Generated waypoint hits (zone==1) ---
idx_zone = find(traj_zone==1);
plot(traj_pos(idx_zone,2), traj_pos(idx_zone,1), ...
    'sg', 'MarkerSize', 7, 'LineWidth', 1.5);

plot(pos_actual(:,2), pos_actual(:,1), 'b')

title('Actual vs Generated Trajectory (Point Cloud)');
xlabel('Y'); ylabel('X'); grid on;

legend({'Actual','Generated','Input Waypoints','Generated Waypoints','Start'}, ...
    'Location','bestoutside');

hold off;