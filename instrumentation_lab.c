int main(void)
{
    unsigned long checksum;
    clock_t t_start;
    clock_t t_build;
    clock_t t_process;
    clock_t t_reduce;
    double total;
    double build;
    double process;
    double reduce;

    t_start = clock();
    build_dataset();
    t_build = clock();
    process_dataset();
    t_process = clock();
    checksum = reduce_checksum();
    t_reduce = clock();

    if (checksum == 0ul)
        printf("impossible\n");

    total = (double)(t_reduce - t_start) / (double)CLOCKS_PER_SEC;
    build = (double)(t_build - t_start) / (double)CLOCKS_PER_SEC;
    process = (double)(t_process - t_build) / (double)CLOCKS_PER_SEC;
    reduce = (double)(t_reduce - t_process) / (double)CLOCKS_PER_SEC;

    printf("TOTAL seconds: %.6f\n", total);
    printf("BUILD_DATA seconds: %.6f\n", build);
    printf("PROCESS seconds: %.6f\n", process);
    printf("REDUCE seconds: %.6f\n", reduce);

    return 0;
}
