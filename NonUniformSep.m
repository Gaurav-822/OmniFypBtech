figure; clf; hold on; grid on; axis equal;

colors = lines(length(all_segments));

for i = 1:length(all_segments)
    seg = all_segments{i};
    
    scatter(seg(:,2), seg(:,1), ...
        12, ...                 % point size
        colors(i,:), ...
        'filled');
end

% waypoints
scatter(pos(:,2), pos(:,1), ...
    60, 'r', 'filled', 'o');

xlabel('Y');
ylabel('X');
title('Segment-wise Non-uniform Trajectory (Sample Points)');

legend_strings = arrayfun(@(i) sprintf('Seg %d',i), ...
                 1:length(all_segments), ...
                 'UniformOutput', false);

legend([legend_strings {'Waypoints'}]);