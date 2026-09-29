# SK하이닉스 코딩테스트 연습 환경
FROM ubuntu:26.04

# g++ 컴파일러, 로케일, vim 설치
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        g++ \
        locales \
        vim \
    && rm -rf /var/lib/apt/lists/*

# 한글(UTF-8) 로케일 생성 및 기본값 설정
RUN sed -i 's/^# *ko_KR.UTF-8 UTF-8/ko_KR.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i 's/^# *en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    locale-gen
ENV LANG=ko_KR.UTF-8
ENV LC_ALL=ko_KR.UTF-8

# vim이 로케일과 무관하게 항상 UTF-8로 열리도록 설정
COPY .vimrc /root/.vimrc

# 연습 문제/템플릿 복사
WORKDIR /root/coding_test
COPY . /root/coding_test

CMD ["/bin/bash"]
