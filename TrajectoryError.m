sampling_time = 0.001;

t = (0:size(traj_generated,1)-1)' * sampling_time;
ref_traj = [t traj_pos];

assignin('base','ref_traj', ref_traj);
