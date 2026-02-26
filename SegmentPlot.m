% Create a new figure and hold it to plot multiple things
figure;
hold on;
grid on;

% Define a set of colors to differentiate the segments
colors = ['r', 'g', 'b', 'm', 'c', 'y']; 
num_segments = length(all_segments);

% 1. Plot each trajectory segment in 2D as discrete points
for i = 1:num_segments
    % Extract the current segment's data
    segment_data = all_segments{i};
    
    % Pick a color (loops back to the start of the color list if needed)
    c = colors(mod(i-1, length(colors)) + 1);
    
    % Plot the segment in 2D as discrete points
    % 'LineStyle', 'none' removes the line
    % 'Marker', '.' makes each step show as a dot
    plot(segment_data(:,1), segment_data(:,2), ...
          'LineStyle', 'none', 'Marker', '.', 'Color', c, 'MarkerSize', 8, ...
          'DisplayName', sprintf('Segment %d Points', i));
end

% 2. Plot and label the original waypoints
% Scatter plot for the main waypoints in 2D so they stand out
scatter(pos(:,1), pos(:,2), 100, 'k', 'filled', ...
    'DisplayName', 'Waypoints');

% Create labels (A, B, C...) based on the number of points
labels = char('A' - 1 + (1:num_segments)'); 

% Add the text labels slightly offset from the points so they are readable
for i = 1:num_segments
    text(pos(i,1), pos(i,2) + 0.02, labels(i), ...
        'FontSize', 14, 'FontWeight', 'bold');
end

% 3. Format the plot
xlabel('X Position');
ylabel('Y Position');
title('2D Discrete Point Trajectory Visualization');
legend('Location', 'best');
axis equal; % Keeps the X and Y scale proportional

hold off;